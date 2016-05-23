// 7_람다11
#include <iostream>
using namespace std;

void goo(int a, int b)
{
	int v = 10;

	auto f = [=]() { return v + a + b;};

	cout << sizeof(f) << endl; // 12.. 즉, 함수 인자도 지역변수입니다.
}



class Test
{
	int data;
public:

	void foo() // foo( Test* this)
	{
		//auto f1 = []() { data = 20;}; // error, not capture lambda 이므로

		//auto f1 = [data]() { data = 20;}; // error. 지역변수가 아님

		// this를 값으로 캡쳐 - 모든 멤버 data를 캡쳐
		// this(객체 주소)가 값으로 캡쳐..
		auto f1 = [ this ]() { data = 20;}; // ok
		//auto f1 = [=]() { data = 20;}; // ok

		f1();
		cout << data << endl;

		// C++17에서는 *this 캡쳐가 가능해집니다.
	//	auto f1 = [*this]() { data = 20;}; // ok
	}
};

int main()
{
	Test t;
	t.foo();
}




