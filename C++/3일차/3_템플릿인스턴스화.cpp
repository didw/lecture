// 3_���ø��ν��Ͻ�ȭ

// �Ʒ� �ڵ尡 �Լ� ���ø��� ����� ����Ҷ� �����Ϸ��� ���� �Ͻ��� �߷�(deduction)��
// �Ұ����ϰ� �ϴ� �ڵ� �Դϴ�.

template<typename T> struct identity
{
	typedef T type;
};

//template<typename T> void foo(T a)

template<typename T> void foo( typename identity<T>::type a)
{

}

int main()
{
	//foo(10);    // �����Ϸ��� �Ͻ��� �߷��� ���� �ʹ�.
	foo<int>(10);
}