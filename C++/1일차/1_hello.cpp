#include <iostream>
using namespace std;

// ���� 2 page
int main()
{
	cout << "hello" << endl;

	int n1 = 0b101;
	
	cout << n1 << endl;

	int n2 = 1'000'000;

	auto n3 = n2; // �캯�� Ÿ�� �����ؼ� �º��� Ÿ������ ������ �޶�

	decltype(n3) n4; // n3�� ����Ÿ�Ժ��� n4

	int x[10] = { 1,2,3 };

	//decltype(x[0]) n5; // n5 ? int&
	int& r = n1;
	auto a2 = r; // a2�� int& �� �ƴ϶�  int �̴�.


	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}

	for (int a : x)
		cout << a << endl;
}

// trailing return �Ǵ� suffix return type �̶�� �θ��� ����.
auto foo() -> int
{
	return 0;
}

// ���� �ϴ� �� : Ctrl + Shift + B
// ���� + ���� : Ctrl + F5