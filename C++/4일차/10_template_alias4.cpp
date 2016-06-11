#include <iostream>
#include <type_traits>
using namespace std;

/*
// C++14부터 모든 type traits 에 대한 using 별칭이 제공됩니다.

template<typename T> 
using remove_pointer_t = typename remove_pointer<T>::type;
*/

template<typename T> void foo(T a)
{
	// T에서 포인터를 제거한 타입의 변수 n을 선언해 보세요.. 정확히 해보세요
	typename remove_pointer<T>::type n;  // C++11

	remove_pointer_t<T> n;				// C++14
}

int main()
{
	int n = 0;
	foo(&n);
}


// www.boost.org
// C:\Program Files(x86)\Microsoft Visual Studio 14.0\VC\bin

// vcbar32.bat

