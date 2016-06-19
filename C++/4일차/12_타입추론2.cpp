#include <iostream>
using namespace std;

// ��Ģ 1. param Ÿ���� �� Ÿ���϶�
//         �Լ� ���ڰ� ���� const, volatile, reference �Ӽ��� ��� �����Ѵ�.
template<typename T> void foo(T param)
{
	// RTTI�� ����� T Ÿ�� Ȯ�ΰ���
	cout << typeid(T).name() << endl;
}

int main()
{
	int n = 1;
	const int c = n;
	int&  r = n;
	const int& cr = c;

	foo(n); // T : int
	foo(c); // T : int
	foo(r); // T : int
	foo(cr); // T : int
}

