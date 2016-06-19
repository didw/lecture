#include <iostream>
using namespace std;

// traits의 종류
// 1. 타입에 대한 질의
// 2. 타입에 대한 변형/세부 타입 얻기

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






