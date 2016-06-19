// 15_decltype추론3 - 3일차 완벽한 전달자에서 logTime 복사해 오세요

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

// return 문이 하나라면 auto 만 적어도 됩니다.
// 원본 함수가 참조를 리턴할수도 있으므로 decltype(auto)로 해야 합니다.
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



