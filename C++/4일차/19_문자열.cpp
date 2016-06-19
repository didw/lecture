// 19_문자열 - 226 page Raw String
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 정규 표현식등에서 \ 표현을 많이 사용합니다.
	string s1 = "hello\\world";
	cout << s1 << endl;

	// \ 를 한번만 써도 되는 문자열 탄생
	string s2 = R"(hello\world)";
	cout << s2 << endl;

	// " 출력하는법 : 종료 조건이 )" 이므로 "는 그냥 적으면 된다.
	string s3 = R"(hello"world)";


	// )"를 출력하는 법 : 시작과 끝의 토큰을 변경하면 된다.
	string s4 = R"***(hello)"world)***";

	cout << s4 << endl;
}