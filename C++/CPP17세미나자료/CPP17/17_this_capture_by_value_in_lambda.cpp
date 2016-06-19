
#include <iostream>
#include <functional>
using namespace std;

function<void()> func;

class Test
{
	int data;
public:
	void foo()
	{
		// this Ä¸ÃÄ..
		auto f1 = [=]() { data = 20; cout << data << endl; };

		func = f1;

		// C++17 capture by value
		auto f2 = [=, *this]{ data = 20; cout << data << endl; }; 
	}
};
int main()
{
	Test* p = new Test;

	p->foo();

	delete p;

	func();
}



