// 람다 8 - 33 page
#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20;


//	auto f1 = [=](int a) { v1 = 100; v2 = 200;};// error. ()연산자가 상수함수

//	auto f2 = [=](int a) mutable { v1 = 100; v2 = 200;};// ok. ()연산자가 비상수함수
														// 하지만, 복사본 변경

	// 참조에 의한 캡쳐
	auto f3 = [&](int a) { v1 = 100; v2 = 200;};//ok. 원본 변경
	f3(0);

	cout << v1 << endl; // 100


	// [&] 를 사용했을때 컴파일러가 만드는 클래스
	class LambdaClass
	{
		int& v1;
		int& v2; 
	public:
		LambdaClass(int& a, int& b) : v1(a), v2(b) {}

		inline void operator()(int a) const
		{
			v1 = 100; // ok. 
			v2 = 200;
		}
	};
	auto f4 = LambdaClass(v1, v2); // 클로져 만들때 지역변수를 값으로 전달
}
// www.cppreference.com 을 자주 활용하세요..











