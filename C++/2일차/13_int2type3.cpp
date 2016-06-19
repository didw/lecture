// 13_int2type
#include <iostream>
#include <type_traits>
using namespace std;



// �����Ϳ� �����Ͱ� �ƴ� ����� �Լ��� �Լ� �����ε��Ѵ�.

template<typename T> void printv_imp(T a, YES)
{
	cout << a << " : " << *a << endl;
}

template<typename T> void printv_imp(T a, NO)
{
	cout << a << endl;
}


template<typename T> void printv(T a)
{
	// �����ε��� �Լ��� ������ ������ �ð��� �����˴ϴ�.
	printv_imp(a, is_pointer<T>::value);
}




int main()
{
	int n = 10;

	printv(n);

}



