// 2_rvalue

int x = 10;
int  foo() { return x; }
int& goo() { return x; }

// lvalue : ��ȣ�� ���ʰ� �����ʿ� ��� �ü� �ִ�.
// rvalue : ��ȣ�� �����ʿ��� �ü� �ִ�.


int main()
{
	int v1 = 10, v2 = 20;

	v1 = 10;

	v2 = v1;
	10 = v2; // error

	foo() = 10; // error
	goo() = 10; // ok..

	int* p1 = &v1;
	int* p2 = &10;

	const int c = 10;
	c = 20; // �����Ұ����� lvalue (�̸��� �ְ�, �޸𸮿� ��� ����, �ּҵ� ���Ҽ��ִ�.)
}


