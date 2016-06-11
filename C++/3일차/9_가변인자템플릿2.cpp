#include <iostream>
using namespace std;

void goo(int a, double d, int n)
{
	cout << "goo" << endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args : parameter pack �̶�� �θ��ϴ�.
	cout << sizeof...(args) << endl;
	cout << sizeof...(Types) << endl;

	// parameter pack�� �ٸ��Լ��� �������� pack�� Ǯ���� ������ �Ѵ�.
	// Pack Expansion
	goo( args... );  // ++args...
}

int main()
{
	foo(1, 3.4, 4); // Types : int, double, int
				    // args  : 1, 3.4, 4
}









