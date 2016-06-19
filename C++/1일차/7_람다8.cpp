// 람다 8 - 33 page
#include <iostream>
using namespace std;

int g = 10;

int main()
{
	int v1 = 10, v2 = 20;


	auto f1 = [](int a) { return a + g;}; // ok.. 전역변수는 모든 곳에서 접근가능

	//auto f2 = [](int a) { return a + v1;};// error.기본적으로 지역변수는 사용할수 없다.

	// [=] : 지역변수를 값으로 캡쳐
	auto f3 = [=](int a) { return a + v1;};// ok
	//auto f4 = [=](int a) { v1 = 30; return a + v1;}; // error. v1은 읽기만 가능



	// mutable 람다 : ()연산자 함수를 비상수 함수로 만들어 달라는 지시어
	auto f5 = [=](int a) mutable { v1 = 30; v2 = 10; return a + v1;};

	f5(0); // v1 = 30이 실행되었지만 복사본이다.

	cout << v1 << endl; // 10


	cout << sizeof(f5) << endl; // 8



	/*

	// [=] 를 사용했을때 컴파일러가 만드는 클래스
	class LambdaClass
	{
		int v1;
		int v2; // 지역변수의 값을 보관하기 위한 멤버 data
	public:
		LambdaClass(int a, int b) : v1(a), v2(b) {}

		inline void operator()(int a) //const
		{
			v1 = 30; // error. 상수함수에서 멤버 값을 변경할수 없다.
			return a + v1;
		}
	};

	auto f4 = LambdaClass(v1, v2); // 클로져 만들때 지역변수를 값으로 전달
	*/
}












