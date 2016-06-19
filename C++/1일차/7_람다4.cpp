#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// 30 page 7번. 람다와 타입
int main()
{
	auto f1 = [](int a, int b) { return a + b;}; //class LambdaClass {};LambdaClass();
	
	auto f2 = [](int a, int b) { return a + b;};

	f2 = [](int a, int b) { return a + b;}; // 될까요 ?error
					// auto 변수에 담은 람다 표현식은 
					// 다른 람다 표현식으로 대입될수 없다.


	// RTTI기술을 사용하면 컴파일러가 만든 클래스 이름 조사 가능
	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl; 

	// 모든 람다 표현식은 다른 타입이다.
}




