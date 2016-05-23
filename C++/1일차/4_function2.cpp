// 4_function - 20 page
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders; // _1, _2, _3 . ....


void foo(int a, int b, int c, int d)
{
	printf("%d %d %d %d\n", a, b, c, d);
}

int main()
{
	function<void(int, int)> f;

	f = bind(&foo, 3, _2, _1, 8); // ? 완성하세요

	f(5, 9); // 3, 9, 5, 8 이 나와야 합니다.
}






