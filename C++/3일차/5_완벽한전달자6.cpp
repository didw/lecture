// 4_완벽한전달자 - 아주 중요한 개념.. 141 page 부터.
#include <iostream>
using namespace std;

void foo(int a) {         }
void goo(int& a) { a = 20; }
void hoo(int&& a) { }

void koo(int a, int b, int& c) { cout << "koo" << endl; }

template<typename F, typename ... T> void logTime(F f, T&& ... arg)
{
	// C++ 표준에 이미 forward<> 가 있습니다.
	// rvalue로 캐스팅하는 함수 입니다.
	f(forward<T>(arg)... );  
}

int main()
{
	int n = 0;

	logTime(koo, 10, 20, n);    // koo(10,20,n);


	logTime(foo, 10);
	logTime(goo, n);
	logTime(hoo, 10);
}




