#include <iostream>
using namespace std;

// C++11/14 ���� �̹� ���� traits�� �����˴ϴ�. 102 ~ 104 page
#include <type_traits>

template<typename T> void foo(const T& a)
{
	if (is_array<T>::value)
	{
		cout << "�迭�Դϴ�. ũ��� " << extent<T, 0>::value << endl;
	}

	// typename remove_pointer<T>::type  n
}
int main()
{
	int x[10] = { 1,2 };
	foo(x);
}