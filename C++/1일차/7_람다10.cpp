// ���� 8 - 33 page
#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20, v3 = 30;

	auto f1 = [=]() {}; // ��� ���������� ������ ĸ��
	auto f2 = [&]() {}; // ��� ���������� ������ ĸ��

	auto f3 = [v1]() {}; // v1�� ������ ĸ��
	auto f4 = [&v1]() {}; // v1�� ������ ĸ��

	auto f4 = [v1, &v2]() {}; // v1�� ��, v2�� ����

	auto f5 = [=, &v2]() {}; // v2��  ����, �������� ��

	auto f5 = [=, v2]() {}; // error
	auto f5 = [&, &v2]() {}; // error

	auto f5 = [&, v2]() {}; // ok..


}












