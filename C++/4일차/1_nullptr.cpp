//1_nullptr - 190 page

#include <iostream>
using namespace std;


void foo(int a)   { cout << "int" << endl; }
void foo(void* a) { cout << "void*" << endl; }
void goo(char* a) { cout << "goo" << endl; }
// C++ 컴파일러들이 정의하는 NULL

#ifdef __cplusplus
	#define NULL 0
#else
	#define NULL (void*)0
#endif


int main()
{
	foo(0); // int
	foo((void*)0);

	foo(NULL);
	goo(NULL); // C   : void* => 다른 포인터로 암시적 형변환 된다.
			   // C++ : void* => 다른 포인터로 암시적 변환 안됨.

	int  n = 0;
	int* p1 = 0;  // 0 : 정수 이지만 포인터로 암시적 형변환된다.
//	int* p2 = 10; // error
}