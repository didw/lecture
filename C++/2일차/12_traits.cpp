// 12_traits
#include <iostream>
using namespace std;

template<typename T> void printv(T a)
{
	if (T가 포인터 라면)
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





