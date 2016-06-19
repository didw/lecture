// 4_완벽한전달자 - 아주 중요한 개념.. 141 page 부터.
#include <iostream>
using namespace std;

// 개념
// 래퍼함수(logTime같은)를 만들때 함수의 인자를 원본함수에게
// 완벽하게 전달(Perfect Forwarding) 하는 기술.

void foo(int a)   {         }
void goo(int& a)  { a = 20; }
void hoo(int&& a) { }
//void hoo(int& a)  { cout << "ho }

// 해결책 : 함수 오버로딩.

// 1. 인자를 받을때 int& 와 int&&	 버전의 함수를 만든다.

// 2. int&& 버전에서는 원래 함수로 보낼때 인자를 rvalue로 캐스팅해서 보내야 한다
//    static_cast<int&&>(arg)





template<typename F> void logTime(F f, int& arg)
{
	f(static_cast<int&>(arg));
}
template<typename F> void logTime(F f, int&& arg)
{
	// logTime(hoo, 10) 이라고 하면 10은 rvalue 이다.
	// 하지만 arg는 lvalue 이다.!!

	// 원본 함수에 보낼때는 다시 rvalue로 캐스팅해야 한다.
	f(static_cast<int&&>(arg));
}

int main()
{
	int n = 10;
	
	hoo(10); //ok..

	logTime(foo, 10);
	logTime(goo, n);
	logTime(hoo, 10);

	cout << n << endl; // 20
}




