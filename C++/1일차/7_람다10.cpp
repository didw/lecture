// 람다 8 - 33 page
#include <iostream>
using namespace std;

int main()
{
	int v1 = 10, v2 = 20, v3 = 30;

	auto f1 = [=]() {}; // 모든 지역변수를 값으로 캡쳐
	auto f2 = [&]() {}; // 모든 지역변수를 참조로 캡쳐

	auto f3 = [v1]() {}; // v1만 값으로 캡쳐
	auto f4 = [&v1]() {}; // v1만 참조로 캡쳐

	auto f4 = [v1, &v2]() {}; // v1은 값, v2는 참조

	auto f5 = [=, &v2]() {}; // v2만  참조, 나머지는 값

	auto f5 = [=, v2]() {}; // error
	auto f5 = [&, &v2]() {}; // error

	auto f5 = [&, v2]() {}; // ok..


}












