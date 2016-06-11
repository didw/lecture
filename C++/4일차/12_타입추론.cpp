// 12_타입추론- 어렵지만 중요합니다.  - 125 page
#include <iostream>
using namespace std;

template<typename T> void foo(T a)
{
	++a;
	a = 30;
}

int main()
{
	int n = 1;
	const int c = n;
	int&  r = n;

	foo(n); // T : int
	foo(c); // T : ?
	foo(r); // T : ?
}



/*
int main()
{
	int n1 = 10;
	int n2 = n1;

	const int c = 10;

	int n3 = c;

	int& r = n1;
	int n4 = r;
}
*/

