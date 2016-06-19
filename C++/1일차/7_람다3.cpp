#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int x[10] = { 1,2,3 };
	
	// 람다가 활용되는 경우
	// 1. 함수의 인자로 사용
	sort(x, x + 10, [](int a, int b) { return a < b;});

	// 2. auto 변수에 담아서 함수 처럼 사용
	auto f = [](int a, int b) { return a + b;};  // class LambdaClass {}; LambdaClass();

	cout << f(1, 2) << endl;

}




