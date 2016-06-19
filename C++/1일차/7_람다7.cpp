#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;


int main()
{
	// 32 page ���ٿ� ���� Ÿ��

	auto f1 = [](int a, int b) { return a + b;};

	auto f2 = [](int a, int b) -> int { return a + b;};

	auto f3 = [](int a, int b) { if (a == 0) 
										return a; 
								 return b;};

	// return ���� 2�� �̻��̰� ���� �ٸ� Ÿ���� �����Ҷ��� �ݵ��
	// trailing return ǥ����� ����ؼ� ����Ÿ���� ǥ�� �ؾ� �Ѵ�.
	auto f4 = [](int a, int b) -> double { if (a == 0)
									return a;
								return 3.4;};

}












