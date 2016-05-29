// 13_int2type
#include <iostream>
#include <type_traits>
using namespace std;



// 포인터와 포인터가 아닌 경우의 함수로 함수 오버로딩한다.

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
	// 오버로딩된 함수의 선택은 컴파일 시간에 결정됩니다.
	printv_imp(a, is_pointer<T>::value);
}




int main()
{
	int n = 10;

	printv(n);

}



