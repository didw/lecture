// 2_const
#include <iostream>
using namespace std;
// 9 page
int main()
{
//	const int c = 10; // ������ �ð� ���

	int n = 10;
	const int c = n; // runtime ���

	int* p = const_cast<int*>(&c); // ������� �����ϴ� ĳ����
							// C��Ÿ�� ĳ���õ� ����...(int*)&c

	*p = 20;

	cout << c  << endl; // 10   20
	cout << *p << endl; // 20   20
}