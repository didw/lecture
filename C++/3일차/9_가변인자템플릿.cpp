// 9_�����������ø� - 108 page 
#include <iostream>
using namespace std;

template<typename ... T> class xtuple
{
};

// �������� �Լ� ���ø�
template<typename ... T> void foo(T ... arg)
{
}

int main()
{
	foo(1, 3.4, "aa");

	xtuple<int, int> t;
	xtuple<int, int, int, int, int> t5;
}







