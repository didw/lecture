//1_nullptr - 190 page

#include <iostream>
using namespace std;


void foo(int a)   { cout << "int" << endl; }
void foo(void* a) { cout << "void*" << endl; }
void goo(char* a) { cout << "goo" << endl; }
// C++ �����Ϸ����� �����ϴ� NULL

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
	goo(NULL); // C   : void* => �ٸ� �����ͷ� �Ͻ��� ����ȯ �ȴ�.
			   // C++ : void* => �ٸ� �����ͷ� �Ͻ��� ��ȯ �ȵ�.

	int  n = 0;
	int* p1 = 0;  // 0 : ���� ������ �����ͷ� �Ͻ��� ����ȯ�ȴ�.
//	int* p2 = 10; // error
}