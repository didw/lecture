// 13_int2type
#include <iostream>
#include <type_traits>
using namespace std;




template<typename T> void printv(T a)
{
	if ( is_pointer<T>::value  )
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}

int main()
{
	int n = 10;
	
	printv(n);   // 1. 이 코드 때문에 컴파일 에러.






	printv(&n);  // 2
}



