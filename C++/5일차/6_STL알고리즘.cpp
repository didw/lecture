// 6_STL�˰���
#include <iostream>
using namespace std;

// Step 1. xstrchr() �Լ� �����

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
		cout << "ã���� �����ϴ�." << endl;
	else
		cout << *p << endl;
}

