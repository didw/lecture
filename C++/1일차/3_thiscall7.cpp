#include <iostream>
#include "ioacademy.h"  // 카페에서 받은 파일 현재 폴더에 복사해오세요
using namespace std;
using namespace ioacademy;

int foo(int h, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: cout << "LBUTTON" << endl; break;
	case WM_KEYDOWN:     cout << "KEYDOWN" << endl; break;
	}
	return 0;
}

int main()
{
	int h1 = IoMakeWindow(foo);
	int h2 = IoMakeWindow(foo);

	IoProcessMessage();
}


