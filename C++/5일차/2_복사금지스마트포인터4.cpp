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
	T* obj; // int[]*
	UniquePtr(const UniquePtr&) = delete;
	void operator=(const UniquePtr&) = delete;
public:
	inline explicit UniquePtr(T* p = 0) : obj(p) {}

	inline ~UniquePtr()
	{
		//		D d; 
		//		d(obj);  // 함수객체이므로 ()연산자 호출.. 
		D()(obj);
	}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main()
{
	UniquePtr<int> p1(new int);

	UniquePtr<int[]> p2(new int[10]);


	
//	UniquePtr<int, ArrayDelete<int> > p2(new int[10]);

}



