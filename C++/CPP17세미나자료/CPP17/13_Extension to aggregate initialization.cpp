struct A
{
	int a;
};
struct B : A
{
	int b;
};

int main()
{
	int a{ 5 }; // c++14 �ʱ�ȭ ���

	B bbb{ {1},1 }; // ok.. in C++17
}
