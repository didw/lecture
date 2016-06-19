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
	inline void operator()(T* p) // ���� delete�� �Ҹ��� ȣ���� ���ؼ�
	{							 // void*�� �ϸ� �ȵȴ�.
		cout << "delete" << endl;
		delete p;
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

	inline ~UniquePtr() 
	{
//		D d; 
//		d(obj);  // �Լ���ü�̹Ƿ� ()������ ȣ��.. 

		D()(obj);
	}
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main()
{
//	UniquePtr<int, DefaultDelete<int> > p1(new int);

	UniquePtr<int> p1(new int);

	UniquePtr<int, Free> p2( (int*)malloc(100));  // ?
}



