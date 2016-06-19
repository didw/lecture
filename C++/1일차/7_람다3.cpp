#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int x[10] = { 1,2,3 };
	
	// ���ٰ� Ȱ��Ǵ� ���
	// 1. �Լ��� ���ڷ� ���
	sort(x, x + 10, [](int a, int b) { return a < b;});

	// 2. auto ������ ��Ƽ� �Լ� ó�� ���
	auto f = [](int a, int b) { return a + b;};  // class LambdaClass {}; LambdaClass();

	cout << f(1, 2) << endl;

}




