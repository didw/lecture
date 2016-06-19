// 13_Decay7
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void foo(T a)
{
	if (is_array<T>::value)
		cout << "배열입니다." << endl;
}

int main()
{
	int x[3] = { 0 };
	foo(x);
}