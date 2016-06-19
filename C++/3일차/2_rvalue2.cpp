
// rvalue�� ����..
int main()
{
	int v1 = 10;

	// 1. �Ϲ� ���� : lvalue �� ���� �Ҽ� �ִ�.
	int& r1 = v1; // ok
	int& r2 = 10; // error

	// 2. const ���� : lvalue�� rvalue ��� ���� ����
	//					��, ������ const �Ӽ��� �߰��ؼ� �����ϰ� �ȴ�.
	const int& r3 = v1; // ok..
	const int& r4 = 10; // ok..

	// 3. C++ 11 �� rvalue reference  : rvalue �� ���� �Ҽ� �ִ�.
	//        "perfect forwarding"�� move semantics ������ ���� ����

	int&& r5 = v1; // error
	int&& r6 = 10; // ok

}




