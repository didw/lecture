// 19_���ڿ� - 226 page Raw String
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// ���� ǥ���ĵ�� \ ǥ���� ���� ����մϴ�.
	string s1 = "hello\\world";
	cout << s1 << endl;

	// \ �� �ѹ��� �ᵵ �Ǵ� ���ڿ� ź��
	string s2 = R"(hello\world)";
	cout << s2 << endl;

	// " ����ϴ¹� : ���� ������ )" �̹Ƿ� "�� �׳� ������ �ȴ�.
	string s3 = R"(hello"world)";


	// )"�� ����ϴ� �� : ���۰� ���� ��ū�� �����ϸ� �ȴ�.
	string s4 = R"***(hello)"world)***";

	cout << s4 << endl;
}