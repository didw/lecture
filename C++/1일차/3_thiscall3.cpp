// 3_thiscall3 - 16 page
#include <iostream>
#include <windows.h> // win32 api
#include <conio.h> 
using namespace std;

// win32 api���� ������ �Լ� ���
DWORD __stdcall foo(void* p)
{
	return 0;
}
int main()
{
	CreateThread(0, 0, foo, "A", 0, 0); // ������ ����� �Լ�
							// ������ : pthread_create()
}





