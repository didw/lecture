// 15_decltype�߷�3 - 3���� �Ϻ��� �����ڿ��� logTime ������ ������

#include <iostream>
using namespace std;

int x = 10;

int& foo(int a) { return x; }

/*
template<typename F, typename ... T> 
auto logTime(F f, T&& ... arg) -> f(forward<T>(arg)...)
{
	return f(forward<T>(arg)...);
}
*/

// return ���� �ϳ���� auto �� ��� �˴ϴ�.
// ���� �Լ��� ������ �����Ҽ��� �����Ƿ� decltype(auto)�� �ؾ� �մϴ�.
template<typename F, typename ... T>
decltype(auto) logTime(F f, T&& ... arg)
{
	return f(forward<T>(arg)...);
}

int main()
{
	int& r = logTime(foo, 0);
	r = 30;

	cout << x << endl;
}

//int goo()
//auto goo() ->int
//{
//}



