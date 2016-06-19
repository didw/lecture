// 6_함수객체4
#include <stdio.h>


// cl 6_함수객체4.cpp    /FAs   /Ob1   

// notepad 6_함수객체4.asm   


// cmp1, cmp2, Less, Greater 모두 복사 해오세요
struct Less    { inline bool operator()(int a, int b) { return a < b; }};
struct Greater { inline bool operator()(int a, int b) { return a > b; }};
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

template<typename T> void foo(T f)
{
	bool b = f(1, 2);
	printf("결과 : %d\n", b);
}
int main()
{
	Less    f1;
	Greater f2;

	foo(cmp1);
	foo(cmp2); // foo(함수포인터) => 치환 안됨
	foo(f1);   // foo(Less)	   => 치환됨
	foo(f2);   // foo(Greater) => 치환됨
}
// 1. 기계어 코드에는 foo 함수가 몇개 일까요 ?
// 2. 각각의 foo에서 f(1,2)의 인라인 치환 여부를 생각해 보세요 
// 3. 기계어 코드에는 foo를 제외한 함수가 몇개 있을까요 ?






