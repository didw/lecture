// 4_function - 20 page
#include <iostream>
using namespace std;

void foo0()             { printf("foo0 \n"); }
void foo1(int a)        { printf("foo1 \n"); }
void foo2(int a, int b) { printf("foo2 %d %d\n", a, b); }

// 2000년대 중반 C++포함되었고 C++11부터 공식 표준으로 지정된 헤더
#include <functional>

using namespace std::placeholders; // _1, _2, _3 . ....

int main()
{
//	void(*f)() = &foo1; // ?

	function<void()> f = &foo0;
	f();
	f = bind(&foo1, 5);
	f(); // foo1(5)


	function<void(int)> f1 = &foo1;

	f1(5); // ok.. foo1(5)

	f1 = bind(&foo2, _1, 3); // 될까요 ?

	f1(7); // foo2(7,3)
}






