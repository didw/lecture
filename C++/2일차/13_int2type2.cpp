// 13_int2type
#include <iostream>
#include <type_traits>
using namespace std;



// 포인터인 경우와 포인터가 아닌 경우를 따로 함수 템플릿으로 만든다

// T가 포인터일때만 사용되어야 한다. 즉, C++ 함수로 만들어져야한다.
template<typename T> void printv_pointer(T a)
{
	cout << a << " : " << *a << endl;
}
template<typename T> void printv_not_pointer(T a)
{
	cout << a << endl;
}
template<typename T> void printv(T a)
{
	// if 문은 실행시간 조사문입니다.
	// 그래서 컴파일시에는 pointer 버전과 not_pointer 버전의 함수가 
	// 모두 필요하다고 컴파일러가 생각하게 됩니다
	// 그래서 2개 버전이 모두 C++함수로 생성됩니다.
	if (is_pointer<T>::value)  // if ( false )
		printv_pointer(a);
	else
		printv_not_pointer(a);
}




int main()
{
	int n = 10;

	printv(n);  

}



