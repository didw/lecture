#include <iostream>
#include <type_traits>
using namespace std;

/*
// C++14���� ��� type traits �� ���� using ��Ī�� �����˴ϴ�.

template<typename T> 
using remove_pointer_t = typename remove_pointer<T>::type;
*/

template<typename T> void foo(T a)
{
	// T���� �����͸� ������ Ÿ���� ���� n�� ������ ������.. ��Ȯ�� �غ�����
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

