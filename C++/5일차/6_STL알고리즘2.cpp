// 6_STL�˰���
#include <iostream>
using namespace std;


// Step 2. �˻� ������ �Ϲ�ȭ - �κ� ���ڿ� �˻��� �����ϰ� ����

// [first, last) ������ ���� �˻�

char* xstrchr(char* first, char* last, char value)
{
	while ( first != last && *first != value)
		++first;

	return first == last ? 0 : first;
}

int main()
{
	char s[] = "abcdefg";

	char* p = xstrchr(s, s + 4, 'c');

	if (p == 0)
		cout << "ã���� �����ϴ�." << endl;
	else
		cout << *p << endl;
}

