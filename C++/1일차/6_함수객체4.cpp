// 6_�Լ���ü4
#include <stdio.h>


// cl 6_�Լ���ü4.cpp    /FAs   /Ob1   

// notepad 6_�Լ���ü4.asm   


// cmp1, cmp2, Less, Greater ��� ���� �ؿ�����
struct Less    { inline bool operator()(int a, int b) { return a < b; }};
struct Greater { inline bool operator()(int a, int b) { return a > b; }};
inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

template<typename T> void foo(T f)
{
	bool b = f(1, 2);
	printf("��� : %d\n", b);
}
int main()
{
	Less    f1;
	Greater f2;

	foo(cmp1);
	foo(cmp2); // foo(�Լ�������) => ġȯ �ȵ�
	foo(f1);   // foo(Less)	   => ġȯ��
	foo(f2);   // foo(Greater) => ġȯ��
}
// 1. ���� �ڵ忡�� foo �Լ��� � �ϱ�� ?
// 2. ������ foo���� f(1,2)�� �ζ��� ġȯ ���θ� ������ ������ 
// 3. ���� �ڵ忡�� foo�� ������ �Լ��� � ������� ?






