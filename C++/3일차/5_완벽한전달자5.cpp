// 4_�Ϻ��������� - ���� �߿��� ����.. 141 page ����.
#include <iostream>
using namespace std;

void foo(int a) {         }
void goo(int& a) { a = 20; }
void hoo(int&& a) { }

/*
template<typename T> struct identity
{
	typedef T type;
};
*/
// rvalue�� ĳ�����ϴ� �Լ��� �����մϴ�.
template<typename T> T&& xforward(typename identity<T>::type& arg)
{
	return static_cast<typename identity<T>::type&&>(arg);
}

template<typename F, typename T> void logTime(F f, T&& arg)
{
	// 10�� ���Լ��� ���� T&&�� int&&�� �����˴ϴ�.
	// �׷���, arg�� lvalue �Դϴ�.
	// �׷��� xforward���� T&& �� int& �� ����.

	// f(xforward(arg)); // �����Ϸ��� arg�� ���� T�� �߷�.
						 // arg�� lvalue �̹Ƿ� T�� int& 
						 // static_cast<T&&>(arg) �� static_cast<int&>(arg)

	f(xforward<T>(arg)); // ����ڰ� T�� �߷�.. logTime(...10) �̹Ƿ� 
						// ���⼭ T��  int !!
						// static_cast<T&&>(arg) �� �ᱹ static_cast<int&&>(arg)
}


int main()
{
	int n = 0;
	logTime(foo, 10);


	logTime(goo, n); 
	logTime(hoo, 10);
}




