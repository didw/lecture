// 18_사용자정의상수 - 225
#include <iostream>
#include <string>
#include <complex>
using namespace std;

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};
// 226 page 표..
Meter operator""_m(unsigned long long n)
{
	return Meter(n);
}

int main()
{
	float f = 3.4f; // 3.4 : double   3.4 f : float

	Meter me = 3_m; // operator""m(3) 함수가 호출됩니다.

	//Gram gr = 3g;
}





