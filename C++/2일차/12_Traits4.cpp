#include <iostream>
using namespace std;

// traits�� ����
// 1. Ÿ�Կ� ���� ����
// 2. Ÿ�Կ� ���� ����/���� Ÿ�� ���

template<typename T> struct RemovePointer
{
	typedef T type;
};

template<typename T> struct RemovePointer<T*>
{
	typedef T type;
};

template<typename T> void foo( T a )
{
	typename RemovePointer<T>::type n;
}
int main()
{
	int n = 10;
	foo(&n);
}






