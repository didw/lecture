// 10_template_alias - 121 page
#include <iostream>
using namespace std;

// typedef : �ɺ�(�����Ǵ� �Լ� �̸�)�� �ִ� �ڸ��� ������ �ƴ� Ÿ������ ����� �޶�

typedef int a;
typedef int *p;
typedef int x[10];   // x�� int[10] ¥�� Ÿ��

typedef void foo(int a); // foo �� �Լ� Ÿ��

typedef void(*f)(int);



typedef int DWORD;

typedef void(*F)(int);

int main()
{
//	void(*f)(int); 
	F f;
}
