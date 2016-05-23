// ���� 8 - 33 page
#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20;


//	auto f1 = [=](int a) { v1 = 100; v2 = 200;};// error. ()�����ڰ� ����Լ�

//	auto f2 = [=](int a) mutable { v1 = 100; v2 = 200;};// ok. ()�����ڰ� �����Լ�
														// ������, ���纻 ����

	// ������ ���� ĸ��
	auto f3 = [&](int a) { v1 = 100; v2 = 200;};//ok. ���� ����
	f3(0);

	cout << v1 << endl; // 100


	// [&] �� ��������� �����Ϸ��� ����� Ŭ����
	class LambdaClass
	{
		int& v1;
		int& v2; 
	public:
		LambdaClass(int& a, int& b) : v1(a), v2(b) {}

		inline void operator()(int a) const
		{
			v1 = 100; // ok. 
			v2 = 200;
		}
	};
	auto f4 = LambdaClass(v1, v2); // Ŭ���� ���鶧 ���������� ������ ����
}
// www.cppreference.com �� ���� Ȱ���ϼ���..











