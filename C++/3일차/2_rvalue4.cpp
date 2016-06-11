// 2_rvalue4
#include <iostream>
using namespace std;

// ���۷��� �浹(reference collapse)
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

	int& && r7 = v1; // error. �ڵ�� ���� ���۷����� �浹���� �Ҽ��� �����ϴ�.
					// typedef �� template ���鶧�� ��Ģ�� ����˴ϴ�.
}
template<typename T> void foo(T& a) {}

foo<int&>(v1);






