#include <iostream>
using namespace std;

// 1. ����ü ���ø� ���弼��
// 2. typedef T type ��������
// 3. �κ�����ȭ�� ���� Ÿ���� ����(?)�� �����ϼ���.

template<typename T> struct ArrayBaseType
{
	typedef T type;
};

template<typename T, int N> struct ArrayBaseType< T[N] >
{
	typedef T type;
};

template<typename T> void foo(const T& a)
{
	typename ArrayBaseType<int[10]>::type n;  // ArrayBaseType ���弼��
										// �̰�� int�� ���;� �մϴ�.
	cout << typeid(a).name() << endl; //int[10]
	cout << typeid(n).name() << endl; //int
}

int main()
{
	int x[10] = { 0 };

	foo(x);
}