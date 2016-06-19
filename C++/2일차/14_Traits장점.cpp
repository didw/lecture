// 14_Traits����
#include <type_traits>
#include <iostream>
using namespace std;

// �Լ��� �����ϴ� ���
 
// 1. �Լ� �����ε� : Ÿ���� ���� �ƴ� Ÿ�Կ� ���� �Լ� ����..

// 2. traits : Ÿ���� ���� ����� �Լ� ������ ����.

// ������ �Ǽ��� �ٸ��� ó���ϰ� �ʹ�.
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
//	foo_imp(a, is_polymorphic<T>()); // T�ȿ� �����Լ��� �ִ°�?							
}
int main()
{
	int n = 0;
	foo(n);
}
