#include <iostream>
using namespace std;

// 규칙 1. param 타입이 값 타입일때
//         함수 인자가 가진 const, volatile, reference 속성은 모두 제거한다.
template<typename T> void foo(T param)
{
	// RTTI의 기술로 T 타입 확인가능
	cout << typeid(T).name() << endl;
}

int main()
{
	int n = 1;
	const int c = n;
	int&  r = n;
	const int& cr = c;

	foo(n); // T : int
	foo(c); // T : int
	foo(r); // T : int
	foo(cr); // T : int
}

