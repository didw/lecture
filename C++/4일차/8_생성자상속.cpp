// 8_�����ڻ�� - 216 page
#include <iostream>
using namespace std;

class Base
{
public:
	void foo(double a)     { cout << "double" << endl; }
	void foo(int a, int b) { cout << "int, int" << endl; }
};
class Derived : public Base
{
public:
	// �ڽĿ� �ִ� �Լ� �̸��� ������ �θ��Լ��� ��ӵ��� �ʴ´�.
	// ���ڰ� �޶� �Լ� �̸��� ������ �θ� �Լ��� �ڽĿ� ���� ��������.
	void foo(int a) { cout << "int" << endl; }

	// �θ��� foo�� ����Ҽ� �ְ� �ش޶�. - C++98 �����Դϴ�.
	using Base::foo;
};
// ARM : Annoted Reference Manual
int main()
{
	Derived d;
	// ��� ������ ������
	d.foo(3.4); // int
	d.foo(1,2); // error
}

