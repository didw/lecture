#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// 31 page 아래 부분 내용 - 람다와 함수 인자

//void foo( int(*f)(int, int) ) // 1. 함수 포인터 - 인라인 치환 안됨

//void foo(function<int(int,int)> f) // 2. function - 인라인 치환 안됨

template<typename T> void foo(T f) // 3. template - 인라인 치환됨.
{									// foo(const T& f)가 좋다.

}
// void goo(auto a) {}  주의 !!   auto는 함수의 인자로 사용될수 없다.
int main()
{
//	goo(1);
//	goo(3.3);
	foo(  [](int a, int b) { return a + b; }  );
}












