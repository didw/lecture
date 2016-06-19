#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;
#include <windows.h>

void foo(int* p) { delete[] p; }

int main()
{
	// 1. 삭제자 변경하기.
	shared_ptr<int> p1( new int );
	shared_ptr<int> p2( new int[10], foo); // 소멸자에서 delete 대신 foo호출
	shared_ptr<int> p3( new int[10], [](int* p) { delete[] p;} );

	shared_ptr<FILE> p4(fopen("a.txt", "wt"), fclose);

	HANDLE h = CreateEvent(0, 0, 0, 0);
	CloseHandle(h);

	shared_ptr< remove_pointer_t<HANDLE> > p5(CreateEvent(0, 0, 0, 0), CloseHandle);

}












