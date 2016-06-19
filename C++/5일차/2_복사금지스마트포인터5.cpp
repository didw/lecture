// 2_�����������Ʈ������
#include <iostream>
using namespace std;


// ������ �Լ���ü
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

// �迭�϶��� ���� �κ� ����ȭ ����.
// �κ� ����ȭ �Ҷ� ����Ʈ ���ڴ� ǥ������ �ʾƾ� �մϴ�.
template<typename T, typename D > class UniquePtr<T[], D>
{
	T* obj; // int*
	UniquePtr(const UniquePtr&) = delete;
	void operator=(const UniquePtr&) = delete;
public:
	inline explicit UniquePtr(T* p = 0) : obj(p) {}

	inline ~UniquePtr() { D()(obj); }

	// �迭 �����϶��� [] �����ڵ� �����Ѵ�.
	inline T& operator[](int index) { return obj[index]; }

	// ->�� *�� �־ ������. C++ ǥ���� �����ϱ�� �߽��ϴ�.
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



