// 13_int2type
#include <iostream>
#include <type_traits>
using namespace std;


// 아래 템플릿이 핵심입니다.
template<int N> struct int2type
{
	enum { value = N };
};
/*
int main()
{
	foo(0);
	foo(1); // 0, 1은 같은 타입이다.  foo(0), foo(1)은 같은 함수 호출

	int2type<0> t0;
	int2type<1> t1;

	foo(t0);
	foo(t1); // t0, t1 은 다른 타입이다. foo(t0), foo(t1) 은 다른 함수 호출
}
*/







// www.google.com 에서  "C++ IDioms" 라고 검색해 보세요..

// 첫번째 링크 클릭


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
	// 오버로딩된 함수의 선택은 컴파일 시간에 결정됩니다.

	printv_imp(a, int2type< is_pointer<T>::value >() );

					// 포인터라면   : int2type<1>() 
					// 포인터아니면 : int2type<0>() 
				
}







int main()
{
	int n = 10;

	printv(n);

}



