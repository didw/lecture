// 2_복사금지스마트포인터
#include <iostream>
using namespace std;


// 삭제자 함수객체
struct Free
{
	inline void operator()(void* p)
	{
		cout << "Free" << endl;
		free(p);
	}
};

template<typename T> struct DefaultDelete
{
	inline void operator()(T* p)
	{
		cout << "delete" << endl;
		delete p;
	}
};
template<typename T> struct DefaultDelete<T[]>
{
	inline void operator()(T* p)
	{
		cout << "delete[]" << endl;
		delete[] p;
	}
};

//-------------------------------------------
template<typename T, typename D = DefaultDelete<T> > class UniquePtr
{
	T* obj;
	UniquePtr(const UniquePtr&) = delete;
	void operator=(const UniquePtr&) = delete;
public:
	inline explicit UniquePtr(T* p = 0) : obj(p) {}
	inline ~UniquePtr()	{	D()(obj);	}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

// 배열일때를 위한 부분 전문화 버전.
// 부분 전문화 할때 디폴트 인자는 표시하지 않아야 합니다.
template<typename T, typename D > class UniquePtr<T[], D>
{
	T* obj; // int*
	UniquePtr(const UniquePtr&) = delete;
	void operator=(const UniquePtr&) = delete;
public:
	inline explicit UniquePtr(T* p = 0) : obj(p) {}

	inline ~UniquePtr() { D()(obj); }

	// 배열 버전일때는 [] 연산자도 제공한다.
	inline T& operator[](int index) { return obj[index]; }

	// ->와 *가 있어도 되지만. C++ 표준은 제거하기로 했습니다.
//	inline T* operator->() { return obj; }
//  inline T& operator*() { return *obj; }
};
int main()
{
	UniquePtr<int> p1(new int);
	UniquePtr<int[]> p2(new int[10]);

	p2[0] = 10;// ok..
	*p2 = 10; // error

	p1[0] = 10; // error
	*p1 = 10; //ok


	//	UniquePtr<int, ArrayDelete<int> > p2(new int[10]);

}



