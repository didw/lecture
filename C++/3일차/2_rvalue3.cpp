#include <iostream>
using namespace std;

// ������ �Լ� �����ε� - 48 page

void foo(int& a)       { cout << "int&" << endl; }
void foo(const int& a) { cout << "const int&" << endl; }
void foo(int&&)        { cout << "int&&" << endl; }

int main()
{
	int v1 = 10;

//	foo(v1); // int& ������ const int& 
//	foo(10); // int&& ������ const int&&

	int& r1 = v1;
//	foo(r1); // 1

	int&& r2 = 10;  // 10�� rvalue ������
					// 10�� ����Ű�� rvalue reference �� ���� ��ü�� lvalue�̴�.
					// "�̸��� �ִ� rvalue reference �� ������ lvalue�̴�."
					
					// rvalue�� rvalue reference�� ������ �����ϼ���.

	foo(r2); // r2�� lvalue �̹Ƿ� int&

	foo(static_cast<int&&>(r2)); // int&& 
								// �� ĳ������ r2�� _rvalue_�� ĳ�����ϴ� �ڵ� �Դϴ�
}





