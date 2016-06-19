// 4_�Ϻ��������� - ���� �߿��� ����.. 141 page ����.
#include <iostream>
using namespace std;

// ����
// �����Լ�(logTime����)�� ���鶧 �Լ��� ���ڸ� �����Լ�����
// �Ϻ��ϰ� ����(Perfect Forwarding) �ϴ� ���.

void foo(int a)  {         }
void goo(int& a) { a = 20; }

// �ذ�å : �Լ� �����ε�.
// 1. ���ڸ� ������ int& �� int&&	 ������ �Լ��� �����.

template<typename F> void logTime(F f, int& arg)
{
	f(arg);
}
template<typename F> void logTime(F f, int&& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	logTime(foo, 10);
	logTime(goo, n);

	cout << n << endl; // 20
}




