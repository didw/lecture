// 4_완벽한전달자 - 아주 중요한 개념.. 141 page 부터.
#include <iostream>
using namespace std;

void foo(int a) {         }
void goo(int& a) { a = 20; }
void hoo(int&& a) { }

/*
template<typename T> struct identity
{
	typedef T type;
};
*/
// rvalue로 캐스팅하는 함수를 제공합니다.
template<typename T> T&& xforward(typename identity<T>::type& arg)
{
	return static_cast<typename identity<T>::type&&>(arg);
}

template<typename F, typename T> void logTime(F f, T&& arg)
{
	// 10이 이함수에 오면 T&&는 int&&로 결정됩니다.
	// 그런데, arg는 lvalue 입니다.
	// 그래서 xforward에서 T&& 는 int& 로 결정.

	// f(xforward(arg)); // 컴파일러가 arg를 보고 T를 추론.
						 // arg는 lvalue 이므로 T는 int& 
						 // static_cast<T&&>(arg) 는 static_cast<int&>(arg)

	f(xforward<T>(arg)); // 사용자가 T를 추론.. logTime(...10) 이므로 
						// 여기서 T는  int !!
						// static_cast<T&&>(arg) 은 결국 static_cast<int&&>(arg)
}


int main()
{
	int n = 0;
	logTime(foo, 10);


	logTime(goo, n); 
	logTime(hoo, 10);
}




