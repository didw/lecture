// 14_Traits 총정리

#include <iostream>
using namespace std;

#include <type_traits>   // 1. 헤더 이름 외워 두세요


template<typename T> void foo_imp(const T& a, true_type)
{
	cout << "true" << endl;

	// 여기서는 *a 사용가능.
}

template<typename T> void foo_imp(const T& a, false_type)
{
	cout << "false" << endl;
}

template<typename T> void foo(const T& a)
{
	// T가 포인터 인지 조사하는 2가지 방법

	// 1. value로 조사 - "*a" 라는 코드가 나오면 안된다.

	if (is_pointer<T>::value)
	{
		cout << "포인터" << endl;
		//*a = 10;
	}

	// 2. 함수 오버로딩 사용 - "*a" 를 사용해도 된다.
	foo_imp( a, is_pointer<T>() );
}

int main()
{
	int n = 10;
	foo(&n);
	foo(n);
}