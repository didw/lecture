#include <iostream>
#include "ioacademy.h"  // 카페에서 받은 파일 현재 폴더에 복사해오세요
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
//18 page 입니다.