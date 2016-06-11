// 4_완벽한전달자 - 아주 중요한 개념.. 141 page 부터.
#include <iostream>
using namespace std;

// 개념
// 래퍼함수(logTime같은)를 만들때 함수의 인자를 원본함수에게
// 완벽하게 전달(Perfect Forwarding) 하는 기술.

void foo(int a)  {         }
void goo(int& a) { a = 20; }

// 해결책 : 함수 오버로딩.
// 1. 인자를 받을때 int& 와 int&&	 버전의 함수를 만든다.

template<typename F> void logTime(F f, int& arg)
{
	f(arg);
}
template<typename F> void logTime(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	logTime(foo, 10);
	logTime(goo, n);

	cout << n << endl; // 20
}




