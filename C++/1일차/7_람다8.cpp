// ���� 8 - 33 page
#include <iostream>
using namespace std;

int g = 10;

int main()
{
	int v1 = 10, v2 = 20;


	auto f1 = [](int a) { return a + g;}; // ok.. ���������� ��� ������ ���ٰ���

	//auto f2 = [](int a) { return a + v1;};// error.�⺻������ ���������� ����Ҽ� ����.

	// [=] : ���������� ������ ĸ��
	auto f3 = [=](int a) { return a + v1;};// ok
	//auto f4 = [=](int a) { v1 = 30; return a + v1;}; // error. v1�� �б⸸ ����



	// mutable ���� : ()������ �Լ��� ���� �Լ��� ����� �޶�� ���þ�
	auto f5 = [=](int a) mutable { v1 = 30; v2 = 10; return a + v1;};

	f5(0); // v1 = 30�� ����Ǿ����� ���纻�̴�.

	cout << v1 << endl; // 10


	cout << sizeof(f5) << endl; // 8



	/*

	// [=] �� ��������� �����Ϸ��� ����� Ŭ����
	class LambdaClass
	{
		int v1;
		int v2; // ���������� ���� �����ϱ� ���� ��� data
	public:
		LambdaClass(int a, int b) : v1(a), v2(b) {}

		inline void operator()(int a) //const
		{
			v1 = 30; // error. ����Լ����� ��� ���� �����Ҽ� ����.
			return a + v1;
		}
	};

	auto f4 = LambdaClass(v1, v2); // Ŭ���� ���鶧 ���������� ������ ����
	*/
}












