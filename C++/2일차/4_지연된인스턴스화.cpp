// 3_�������ν��Ͻ�ȭ - 77 page 3��.
/*
class A
{
	int data;
public:
	void foo(int n) { *n = 10; } // error.
};

int main()
{
	A a;
}
*/

// template code   => C++ �ڵ����  => C++�ڵ� ������

// ������ ���� �Լ��� C++ �ڵ�� �������� ����..

template<typename T> class A
{
	T data;
public:
	void foo(T n) { *n = 10; } // error.
};

int main()
{
	A<int> a;
	//a.foo(0);
}
