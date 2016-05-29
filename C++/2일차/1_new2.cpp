// 1_new2
#include <iostream>
using namespace std;

// operator new()함수를 재정의 할수 있습니다.

void* operator new(size_t sz)
{
	cout << "new " << sz << endl;
	return malloc(sz);
}

void* operator new(size_t sz, char* s, int n)
{
	cout << "new2 " << sz << endl;
	return malloc(sz);
}

void operator delete(void* p)
{
	cout << "delete" << endl;
	free(p);
}
int main()
{
	int* p1 = new("aaa", 2) int;
	delete p1;
}


