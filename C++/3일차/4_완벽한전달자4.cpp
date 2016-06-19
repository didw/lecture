// 4_완벽한전달자 - 아주 중요한 개념.. 141 page 부터.
#include <iostream>
using namespace std;

// 개념

// 완벽한 전달자를 만드는 방법

// 1. 함수 인자를 만들때  _T&&_  로 받는다.
//    lvalue와 rvalue를 모두 받아서.. 각각 int&, int&& 버전이 함수 를 생성

// 2. 원본 함수에 보낼때  캐스팅 _static_cast<T&&>_ 해서 전달한다.



void foo(int a)   {         }
void goo(int& a)  { a = 20; }
void hoo(int&& a) { }




// int&  : lvalue reference
// int&& : rvalue reference
// T&&   : Forwarding reference
//         인자로 lvalue가 오면   T는 lvalue 참조(&)로 결정
//               rvalue 가오면       값 타입으로 결정

// 즉 n이 오면 : T => int&   T&& : int& &&   => int&
//   10이 오면 : T => int    T&& : int&&
 
template<typename F, typename T> void logTime(F f, T&& arg)
{
	// int&&로 인자가 결정되었을때는 rvalue로 캐스팅 되어야 한다.
	f(static_cast<T&&>(arg));
}


int main()
{
	int n = 0;
	logTime(foo, 10); // logTime( ... , int&&) 인 함수 생성
	logTime(goo, n);  // logTime( ... , int&)  인 함수 생성.
	logTime(hoo, 10);
}




