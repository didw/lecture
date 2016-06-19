// 31_string_view
#include <iostream>
#include <string>
using namespace std;

string_view extract_part(const string_view& s)
{
	return s.substr(2, 3);
}

int main()
{
	string s = "abcdefg";

	if ( extract_part(s).front() == 'c')
	{
	}
}

int main()
{
	char s1[] = "hello"; // r/w  mutable
	char* s2 = "hello"; // r

	string s3("hello");
	string_view s4("hello"); // 포인터와 길이 관리

}


