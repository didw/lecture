// 2_const2
#include <iostream>
using namespace std;

int main()
{
	int s1 = 10;
	int ar1[s1]; // error

	const int s2 = 10;
	int ar2[s2]; // ok

	const int s3 = s1;
	int ar3[s3]; // error. �迭 ũ��� ������ �ð� ����� ����
				// ��, gcc�� �迭 ũ��� ������ �Ǳ� �Ѵ�.
}

void foo(const int c)
{
	int a[c]; // �ɱ�� ? error
}

foo(n)


