
// �迭�� ���ø����� ������
// ��(T)   : �����ͷ� �߷еǾ �ް� �ȴ�.
// ����(T&): ��Ȯ�� �迭�� �߷еǾ �ް� �ȴ�.

template<typename T> void foo(T a, T b)
{
}

template<typename T> void goo(T& a, T& b)
{
}

int main()
{
	foo("apple", "banana");
	goo("apple", "banana"); // error. �� ?
}