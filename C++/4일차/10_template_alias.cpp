// 10_template_alias - 121 page
#include <iostream>
using namespace std;

// typedef : 심볼(변수또는 함수 이름)이 있는 자리를 변수가 아닌 타입으로 만들어 달라

typedef int a;
typedef int *p;
typedef int x[10];   // x는 int[10] 짜리 타입

typedef void foo(int a); // foo 는 함수 타입

typedef void(*f)(int);



typedef int DWORD;

typedef void(*F)(int);

int main()
{
//	void(*f)(int); 
	F f;
}
