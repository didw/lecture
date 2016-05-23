#include <iostream>
using namespace std;
// 35 page 11��
int main()
{
	auto f1 = [](int a) {};
	auto f2 = []() {}; // ���ڰ� ���� ����
	auto f3 = []   {}; // ���ڰ� ������ () ���� ����.
	
	// �Լ� ���ڷδ� auto�� ����Ҽ� ������, ����ǥ���Ŀ����� ��밡��.
	// C++14����
	// ���� 2. �Ʒ� �ڵ忡 ���� �����Ϸ��� ������ Ŭ������ ������ ������
	auto f4 = [](auto a, auto b) { return a + b;};

	cout << f4(1, 2)     << endl;
	cout << f4(1.4, 2.3) << endl;
	cout << f4(1.4, 2)   << endl;
}