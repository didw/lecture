#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// 31 page 
int main()
{
	// ���� ǥ������ ���� ��� ���
	auto f1 = [](int a, int b) { return a + b;}; //class LambdaClass {};LambdaClass();
	
	
	int(*f2)(int, int) = [](int a, int b) { return a + b;};
							// Ŭ���� ��ü�� �Լ� �����ͷ��� ��ȯ �����ڰ� �ִ�.
							// 2������ �ڼ��� ���� �˴ϴ�.
	//f2 = &foo;

	function<int(int,int)> f3 = [](int a, int b) { return a + b;};

	// ������ �ζ��� ġȯ���θ� ������ ������
	f1(1, 2); // �ζ��� ġȯ��.  
	f2(1, 2); // �ζ��� ġȯ �ȵ�
	f3(1, 2); // �ζ��� ġȯ �ȵ�.
}




