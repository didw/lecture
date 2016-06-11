// 8_생성자상속 - 216 page
#include <iostream>
using namespace std;

class Base
{
public:
	void foo(double a)     { cout << "double" << endl; }
	void foo(int a, int b) { cout << "int, int" << endl; }
};
class Derived : public Base
{
public:
	// 자식에 있는 함수 이름과 동일한 부모함수는 상속되지 않는다.
	// 인자가 달라도 함수 이름만 같으면 부모 함수는 자식에 의해 가려진다.
	void foo(int a) { cout << "int" << endl; }

	// 부모의 foo도 사용할수 있게 해달라. - C++98 문법입니다.
	using Base::foo;
};
// ARM : Annoted Reference Manual
int main()
{
	Derived d;
	// 결과 예측해 보세요
	d.foo(3.4); // int
	d.foo(1,2); // error
}

