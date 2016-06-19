// 7_����11
#include <iostream>
using namespace std;

void goo(int a, int b)
{
	int v = 10;

	auto f = [=]() { return v + a + b;};

	cout << sizeof(f) << endl; // 12.. ��, �Լ� ���ڵ� ���������Դϴ�.
}



class Test
{
	int data;
public:

	void foo() // foo( Test* this)
	{
		//auto f1 = []() { data = 20;}; // error, not capture lambda �̹Ƿ�

		//auto f1 = [data]() { data = 20;}; // error. ���������� �ƴ�

		// this�� ������ ĸ�� - ��� ��� data�� ĸ��
		// this(��ü �ּ�)�� ������ ĸ��..
		auto f1 = [ this ]() { data = 20;}; // ok
		//auto f1 = [=]() { data = 20;}; // ok

		f1();
		cout << data << endl;

		// C++17������ *this ĸ�İ� ���������ϴ�.
	//	auto f1 = [*this]() { data = 20;}; // ok
	}
};

int main()
{
	Test t;
	t.foo();
}




