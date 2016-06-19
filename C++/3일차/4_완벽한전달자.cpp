// 4_완벽한전달자 - 아주 중요한 개념.. 141 page 부터.
#include <iostream>
using namespace std;

// 개념
// 래퍼함수(logTime같은)를 만들때 함수의 인자를 원본함수에게
// 완벽하게 전달(Perfect Forwarding) 하는 기술.

void foo(int a)  {         }
void goo(int& a) { a = 20; }

// const & 로 하면 rvalue와 lvalue를 모두 받을수는 있지만..
// 다시 원본함수로 보낼때 const&를 int&로 보낼수 없게 된다.

// 결국 원래 인자에 const속성이 추가되면 안된다.
template<typename F, typename T> void logTime(F f, T& arg)
{
	f(arg);
}
int main()
{
	int n = 10;
//	foo(10);
//	goo(n);

	logTime(foo, 10);
	logTime(goo, n);

	cout << n << endl; // 10
}




