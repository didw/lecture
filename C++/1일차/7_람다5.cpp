#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// 31 page 
int main()
{
	// 람다 표현식을 변수 담는 방법
	auto f1 = [](int a, int b) { return a + b;}; //class LambdaClass {};LambdaClass();
	
	
	int(*f2)(int, int) = [](int a, int b) { return a + b;};
							// 클로져 객체는 함수 포인터로의 변환 연산자가 있다.
							// 2일차에 자세히 배우게 됩니다.
	//f2 = &foo;

	function<int(int,int)> f3 = [](int a, int b) { return a + b;};

	// 다음중 인라인 치환여부를 생각해 보세요
	f1(1, 2); // 인라인 치환됨.  
	f2(1, 2); // 인라인 치환 안됨
	f3(1, 2); // 인라인 치환 안됨.
}




