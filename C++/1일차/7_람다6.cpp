#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// 31 page �Ʒ� �κ� ���� - ���ٿ� �Լ� ����

//void foo( int(*f)(int, int) ) // 1. �Լ� ������ - �ζ��� ġȯ �ȵ�

//void foo(function<int(int,int)> f) // 2. function - �ζ��� ġȯ �ȵ�

template<typename T> void foo(T f) // 3. template - �ζ��� ġȯ��.
{									// foo(const T& f)�� ����.

}
// void goo(auto a) {}  ���� !!   auto�� �Լ��� ���ڷ� ���ɼ� ����.
int main()
{
//	goo(1);
//	goo(3.3);
	foo(  [](int a, int b) { return a + b; }  );
}












