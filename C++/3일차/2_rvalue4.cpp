// 2_rvalue4
#include <iostream>
using namespace std;

// 레퍼런스 충돌(reference collapse)
typedef int&  LR;
typedef int&& RR;

int main()
{
	int v1 = 10;
	LR r1 = v1;
	RR r2 = 10;

	LR&  r3 = v1;  // int& &  =>int&
	LR&& r4 = v1;  // int& && =>int&
	RR&  r5 = v1;  // int&& & =>int&
	RR&& r6 = 10;    // int&& && => int&&

	int& && r7 = v1; // error. 코드로 직접 레퍼런스가 충돌나게 할수는 없습니다.
					// typedef 나 template 만들때만 규칙이 적용됩니다.
}
template<typename T> void foo(T& a) {}

foo<int&>(v1);






