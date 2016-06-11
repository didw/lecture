// 8_생성자상속 - 216 page
#include <iostream>
using namespace std;

class Base
{
	int data;
public:
	Base(int n) : data(n) {}
};
class Derived : public Base
{
public:
	// 부모의 디폴트 생성자가 없으면
	// 자식생성자에서 부모 생성자를 명시적으로 호출해야 한다.
	//Derived(int n) : Base(n) {} // 부모 생성자의 명시적 호출

	// C++11 부모의 생성자도 상속될수 있습니다.
	using Base::Base;

	Derived(int n) : Base(0) { cout << "Derived" << endl; }
};

int main()
{
	Derived d(5);
}



