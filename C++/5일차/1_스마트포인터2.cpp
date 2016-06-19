#include <iostream>
using namespace std;

// Ptr만 복사해오세요
// 1. template 으로 해야 한다.
template<typename T> class Ptr
{
	T* obj;

	int* ref; // 참조계수를 가르킬 포인터
public:
	Ptr(T* p = 0) : obj(p) 
	{
		ref = new int(1); // 한개를 1로 초기화
	}

	// 복사 생성자
	Ptr(const Ptr& p)
	{
		// 얕은 복사 후에
		obj = p.obj;
		ref = p.ref;

		// 참조계수 증가
		++(*ref);
	}

	~Ptr() 
	{
		// 참조계수가 0이면 자원과 참조계수 제거
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;

	Ptr<int> p2 = p1; // 복사 생성자
}