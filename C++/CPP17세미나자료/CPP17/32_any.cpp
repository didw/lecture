// 32_any
#include <iostream>
#include <boost/any.hpp>
using namespace std;
using namespace boost;

void foo(any a)
{
	double d = any_cast<double>(a);

	cout << d << endl;
}
void goo(void* p)
int main()
{
	any a1 = 3;
	any a2 = 3.4;
	any a3 = "aeee";
	Test t;
	any a4 = t;

	char* p = any_cast<char*>(a3);
	foo(3.4);
}
