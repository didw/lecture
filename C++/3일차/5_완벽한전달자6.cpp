// 4_�Ϻ��������� - ���� �߿��� ����.. 141 page ����.
#include <iostream>
using namespace std;

void foo(int a) {         }
void goo(int& a) { a = 20; }
void hoo(int&& a) { }

void koo(int a, int b, int& c) { cout << "koo" << endl; }

template<typename F, typename ... T> void logTime(F f, T&& ... arg)
{
	// C++ ǥ�ؿ� �̹� forward<> �� �ֽ��ϴ�.
	// rvalue�� ĳ�����ϴ� �Լ� �Դϴ�.
	f(forward<T>(arg)... );  
}

int main()
{
	int n = 0;

	logTime(koo, 10, 20, n);    // koo(10,20,n);


	logTime(foo, 10);
	logTime(goo, n);
	logTime(hoo, 10);
}




