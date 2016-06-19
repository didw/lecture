// 14_Traits ������

#include <iostream>
using namespace std;

#include <type_traits>   // 1. ��� �̸� �ܿ� �μ���


template<typename T> void foo_imp(const T& a, true_type)
{
	cout << "true" << endl;

	// ���⼭�� *a ��밡��.
}

template<typename T> void foo_imp(const T& a, false_type)
{
	cout << "false" << endl;
}

template<typename T> void foo(const T& a)
{
	// T�� ������ ���� �����ϴ� 2���� ���

	// 1. value�� ���� - "*a" ��� �ڵ尡 ������ �ȵȴ�.

	if (is_pointer<T>::value)
	{
		cout << "������" << endl;
		//*a = 10;
	}

	// 2. �Լ� �����ε� ��� - "*a" �� ����ص� �ȴ�.
	foo_imp( a, is_pointer<T>() );
}

int main()
{
	int n = 10;
	foo(&n);
	foo(n);
}