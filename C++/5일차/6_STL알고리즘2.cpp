// 6_STL알고리즘
#include <iostream>
using namespace std;


// Step 2. 검색 구간의 일반화 - 부분 문자열 검색이 가능하게 하자

// [first, last) 사이의 선형 검색

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
		cout << "찾을수 없습니다." << endl;
	else
		cout << *p << endl;
}

