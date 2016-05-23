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
	int ar3[s3]; // error. 배열 크기는 컴파일 시간 상수만 가능
				// 단, gcc는 배열 크기로 변수도 되긴 한다.
}

void foo(const int c)
{
	int a[c]; // 될까요 ? error
}

foo(n)


