// 13_Decay7
#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void foo(T a)
{
	if (is_array<T>::value)
		cout << "�迭�Դϴ�." << endl;
}

int main()
{
	int x[3] = { 0 };
	foo(x);
}