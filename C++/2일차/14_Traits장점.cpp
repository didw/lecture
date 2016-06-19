// 14_Traits장점
#include <type_traits>
#include <iostream>
using namespace std;

// 함수를 선택하는 기술
 
// 1. 함수 오버로딩 : 타입의 군이 아닌 타입에 대한 함수 선택..

// 2. traits : 타입의 군을 사용한 함수 선택이 가능.

// 정수와 실수를 다르게 처리하고 싶다.
//void foo(int a)    {}
//void foo(short a) {}

//void foo(double a) {}
//void foo(float  a) {}

//-------------------
template<typename T> void foo_imp(T a, true_type) { cout << "true" << endl; }
template<typename T> void foo_imp(T a, false_type) { cout << "false" << endl; }

template<typename T> void foo(T a)
{
	foo_imp(a, is_integral<T>()); 
//	foo_imp(a, is_polymorphic<T>()); // T안에 가상함수가 있는가?							
}
int main()
{
	int n = 0;
	foo(n);
}
