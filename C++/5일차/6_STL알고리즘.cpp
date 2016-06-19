// 6_STL알고리즘
#include <iostream>
using namespace std;

// Step 1. xstrchr() 함수 만들기

char* xstrchr(char* s, char value)
{
	while ( *s != 0 && *s != value)
		++s;

	return *s == 0 ? 0 : s;
}


int main()
{
	char s[] = "abcdefg";

	char* p = xstrchr(s, 'c');

	if (p == 0)
		cout << "찾을수 없습니다." << endl;
	else
		cout << *p << endl;
}

