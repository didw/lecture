// 4_�Ϻ��������� - ���� �߿��� ����.. 141 page ����.
#include <iostream>
using namespace std;

// ����
// �����Լ�(logTime����)�� ���鶧 �Լ��� ���ڸ� �����Լ�����
// �Ϻ��ϰ� ����(Perfect Forwarding) �ϴ� ���.

void foo(int a)   {         }
void goo(int& a)  { a = 20; }
void hoo(int&& a) { }
//void hoo(int& a)  { cout << "ho }

// �ذ�å : �Լ� �����ε�.

// 1. ���ڸ� ������ int& �� int&&	 ������ �Լ��� �����.

// 2. int&& ���������� ���� �Լ��� ������ ���ڸ� rvalue�� ĳ�����ؼ� ������ �Ѵ�
//    static_cast<int&&>(arg)





template<typename F> void logTime(F f, int& arg)
{
	f(static_cast<int&>(arg));
}
template<typename F> void logTime(F f, int&& arg)
{
	// logTime(hoo, 10) �̶�� �ϸ� 10�� rvalue �̴�.
	// ������ arg�� lvalue �̴�.!!

	// ���� �Լ��� �������� �ٽ� rvalue�� ĳ�����ؾ� �Ѵ�.
	f(static_cast<int&&>(arg));
}

int main()
{
	int n = 10;
	
	hoo(10); //ok..

	logTime(foo, 10);
	logTime(goo, n);
	logTime(hoo, 10);

	cout << n << endl; // 20
}




