// 12_traits
#include <iostream>
using namespace std;

template<typename T> void printv(T a)
{
	if (T�� ������ ���)
		cout << a << " : " << *a << endl;
	else
		cout << a << endl;
}

int main()
{
	int    n = 10;
	double d = 3.4;

	printv(n);
	printv(d);
	printv(&n);
}





