#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;


int main()
{
	// 32 page 람다와 리턴 타입

	auto f1 = [](int a, int b) { return a + b;};

	auto f2 = [](int a, int b) -> int { return a + b;};

	auto f3 = [](int a, int b) { if (a == 0) 
										return a; 
								 return b;};

	// return 문이 2개 이상이고 각각 다른 타입을 리턴할때는 반드시
	// trailing return 표기법을 사용해서 리턴타입을 표기 해야 한다.
	auto f4 = [](int a, int b) -> double { if (a == 0)
									return a;
								return 3.4;};

}












