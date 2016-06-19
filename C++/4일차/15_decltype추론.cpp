#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;
int x = 10;
int& foo() { return x; }

int main()
{
	int n = 10;
	int& r = n;
	auto a1 = r; // 템플릿 추론 규칙
	decltype(r) d1 = r; // r의 선언을 조사해서 사용.즉, 정확한 타입..


//	auto ret = foo();

//	decltype(foo()) ret = foo(); // decltype(foo()) 는 함수 호출이 아니라
								 // foo()함수의 선언을 조사하라는 의미.

	// C++14 : 우변과 동일한 타입으로, 단, 추론규칙은 decltype() 규칙
	decltype(auto) ret = foo();
	ret = 30;


	cout << x << endl;
}







