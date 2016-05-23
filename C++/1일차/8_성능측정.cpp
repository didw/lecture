// 8_��������
#include <iostream>
#include <algorithm>
#include <functional>
#include "logTime.h"   // ī�信�� �ٿ� �޾Ƽ� ���� ������ ������ ������
using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

void test1(int cnt)
{
	int x[1000] = { 1,3,5,7,9,2,4,6,8,10 };

	for (int i = 0; i < cnt; i++)
	{
		sort(x, x + 1000, cmp1);
		sort(x, x + 1000, cmp2);  // cmp1, cmp2 �����ؿ�����
	}
}
void test2(int cnt)
{
	int x[1000] = { 1,3,5,7,9,2,4,6,8,10 };

	less<int>    f1;
	greater<int> f2;
	for (int i = 0; i < cnt; i++)
	{
		sort(x, x + 1000, f1);
		sort(x, x + 1000, f2);  
	}
}   

void test3(int cnt)
{
	int x[1000] = { 1,3,5,7,9,2,4,6,8,10 };

	for (int i = 0; i < cnt; i++)
	{
		sort(x, x + 1000, [](int a, int b) { return  a < b;});
		sort(x, x + 1000, [](int a, int b) { return  a > b;});
	}
}

int main()
{
	logTime(test1, 1000); // test(1000)�� �����ϴµ� �ɸ� �ð��� ����..
	logTime(test2, 1000);
	logTime(test3, 1000);
}





