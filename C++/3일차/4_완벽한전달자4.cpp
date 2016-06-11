// 4_�Ϻ��������� - ���� �߿��� ����.. 141 page ����.
#include <iostream>
using namespace std;

// ����

// �Ϻ��� �����ڸ� ����� ���

// 1. �Լ� ���ڸ� ���鶧  _T&&_  �� �޴´�.
//    lvalue�� rvalue�� ��� �޾Ƽ�.. ���� int&, int&& ������ �Լ� �� ����

// 2. ���� �Լ��� ������  ĳ���� _static_cast<T&&>_ �ؼ� �����Ѵ�.



void foo(int a)   {         }
void goo(int& a)  { a = 20; }
void hoo(int&& a) { }




// int&  : lvalue reference
// int&& : rvalue reference
// T&&   : Forwarding reference
//         ���ڷ� lvalue�� ����   T�� lvalue ����(&)�� ����
//               rvalue ������       �� Ÿ������ ����

// �� n�� ���� : T => int&   T&& : int& &&   => int&
//   10�� ���� : T => int    T&& : int&&
 
template<typename F, typename T> void logTime(F f, T&& arg)
{
	// int&&�� ���ڰ� �����Ǿ������� rvalue�� ĳ���� �Ǿ�� �Ѵ�.
	f(static_cast<T&&>(arg));
}


int main()
{
	int n = 0;
	logTime(foo, 10); // logTime( ... , int&&) �� �Լ� ����
	logTime(goo, n);  // logTime( ... , int&)  �� �Լ� ����.
	logTime(hoo, 10);
}




