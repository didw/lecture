//1_nullptr2

#include <iostream>
using namespace std;
// C++11 : ������ 0�� ��������ϴ�

int main()
{
	int* p = nullptr; // ok
	//int  n = nullptr; // error

	// nullptr �� nullptr_t Ÿ���Դϴ�.
	// ��� Ÿ���� �����ͷ� �Ͻ��� ����ȯ �˴ϴ�.
	nullptr_t a = nullptr;
}