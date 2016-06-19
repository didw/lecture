#include <iostream>
using namespace std;
// 35 page 11번
int main()
{
	auto f1 = [](int a) {};
	auto f2 = []() {}; // 인자가 없는 람다
	auto f3 = []   {}; // 인자가 없으면 () 생략 가능.
	
	// 함수 인자로는 auto를 사용할수 없지만, 람다표현식에서는 사용가능.
	// C++14문법
	// 숙제 2. 아래 코드에 의해 컴파일러가 생성한 클래스를 예측해 보세요
	auto f4 = [](auto a, auto b) { return a + b;};

	cout << f4(1, 2)     << endl;
	cout << f4(1.4, 2.3) << endl;
	cout << f4(1.4, 2)   << endl;
}