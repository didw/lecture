#include <iostream>
using namespace std;

void goo(int a, double d, int n)
{
	cout << "goo" << endl;
}
template<typename ... Types> void foo(Types ... args)
{
	// args : parameter pack 이라고 부릅니다.
	cout << sizeof...(args) << endl;
	cout << sizeof...(Types) << endl;

	// parameter pack을 다른함수에 보낼때는 pack을 풀러서 보내야 한다.
	// Pack Expansion
	goo( args... );  // ++args...
}

int main()
{
	foo(1, 3.4, 4); // Types : int, double, int
				    // args  : 1, 3.4, 4
}









