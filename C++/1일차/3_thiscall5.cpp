#include <iostream>
#include "ioacademy.h"  // ī�信�� ���� ���� ���� ������ �����ؿ�����
using namespace std;
using namespace ioacademy;

void foo(int id)
{
	cout << "foo : " << id << endl;
}

int main()
{
	int n1 = IoSetTimer(500,  foo);
	int n2 = IoSetTimer(1000, foo);

	IoProcessMessage();
}
//18 page �Դϴ�.