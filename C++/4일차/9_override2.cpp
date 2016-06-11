#include <iostream>
using namespace std;
/*
// const 에 대해서
// 1. const는 타입의 앞 또는 뒤에 붙일수 있습니다.  c1, c2는 동일합니다.
const int c1 = 10;
int const c2 = 10;  

// 2. 상수 포인터와 포인터 상수
const int* p1 = &c1; // p1을 따라가면 상수. "상수를 가르키는 포인터"
int const* p2 = &c1; // p1, p2는 동일
int* const p3 = &c1; // 포인터 자체가 상수.
*/



template<typename T> class Base
{
public:
	// "T가 상수이다"
	//virtual void foo(const T a) { cout << "Base foo" << endl; }

	virtual void foo(T const a) { cout << "Base foo" << endl; }
};

class Derived : public Base<int*>
{
public:
	// foo 재정의 해서 Derived foo 나오게 해보세요.. - override 사용하지 마세요
	// "int*가 상수이다"
	//virtual void foo(const int* a) { cout << "Derived foo" << endl; }

	virtual void foo( int* const a) { cout << "Derived foo" << endl; }
};
int main()
{
	Base<int*>* p = new Derived;

	p->foo(0);  // "Derived foo" 나와야 합니다.
}





