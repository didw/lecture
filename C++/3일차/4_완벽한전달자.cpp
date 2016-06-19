// 4_�Ϻ��������� - ���� �߿��� ����.. 141 page ����.
#include <iostream>
using namespace std;

// ����
// �����Լ�(logTime����)�� ���鶧 �Լ��� ���ڸ� �����Լ�����
// �Ϻ��ϰ� ����(Perfect Forwarding) �ϴ� ���.

void foo(int a)  {         }
void goo(int& a) { a = 20; }

// const & �� �ϸ� rvalue�� lvalue�� ��� �������� ������..
// �ٽ� �����Լ��� ������ const&�� int&�� ������ ���� �ȴ�.

// �ᱹ ���� ���ڿ� const�Ӽ��� �߰��Ǹ� �ȵȴ�.
template<typename F, typename T> void logTime(F f, T& arg)
{
	f(arg);
}
int main()
{
	int n = 10;
//	foo(10);
//	goo(n);

	logTime(foo, 10);
	logTime(goo, n);

	cout << n << endl; // 10
}




