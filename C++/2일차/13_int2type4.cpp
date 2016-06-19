// 13_int2type
#include <iostream>
#include <type_traits>
using namespace std;


// �Ʒ� ���ø��� �ٽ��Դϴ�.
template<int N> struct int2type
{
	enum { value = N };
};
/*
int main()
{
	foo(0);
	foo(1); // 0, 1�� ���� Ÿ���̴�.  foo(0), foo(1)�� ���� �Լ� ȣ��

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1 �� �ٸ� Ÿ���̴�. foo(t0), foo(t1) �� �ٸ� �Լ� ȣ��
}
*/







// www.google.com ����  "C++ IDioms" ��� �˻��� ������..

// ù��° ��ũ Ŭ��


template<typename T> void printv_imp(T a, int2type<1> )
{
	cout << a << " : " << *a << endl;
}

template<typename T> void printv_imp(T a, int2type<0> )
{
	cout << a << endl;
}

template<typename T> void printv(T a)
{
	// �����ε��� �Լ��� ������ ������ �ð��� �����˴ϴ�.

	printv_imp(a, int2type< is_pointer<T>::value >() );

					// �����Ͷ��   : int2type<1>() 
					// �����;ƴϸ� : int2type<0>() 
				
}







int main()
{
	int n = 10;

	printv(n);

}



