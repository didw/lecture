// 3_thiscall3 - 16 page
#include <iostream>
#include <windows.h> // win32 api
#include <conio.h> 
using namespace std;

// win32 api에서 스레드 함수 모양
DWORD __stdcall foo(void* p)
{
	return 0;
}
int main()
{
	CreateThread(0, 0, foo, "A", 0, 0); // 스레드 만드는 함수
							// 리눅스 : pthread_create()
}





