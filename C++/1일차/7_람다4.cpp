#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// 30 page 7��. ���ٿ� Ÿ��
int main()
{
	auto f1 = [](int a, int b) { return a + b;}; //class LambdaClass {};LambdaClass();
	
	auto f2 = [](int a, int b) { return a + b;};

	f2 = [](int a, int b) { return a + b;}; // �ɱ�� ?error
					// auto ������ ���� ���� ǥ������ 
					// �ٸ� ���� ǥ�������� ���Եɼ� ����.


	// RTTI����� ����ϸ� �����Ϸ��� ���� Ŭ���� �̸� ���� ����
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl; 

	// ��� ���� ǥ������ �ٸ� Ÿ���̴�.
}




