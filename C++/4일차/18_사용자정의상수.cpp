// 18_��������ǻ�� - 225
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
// 226 page ǥ..
Meter operator""_m(unsigned long long n)
{
	return Meter(n);
}

int main()
{
	float f = 3.4f; // 3.4 : double   3.4 f : float

	Meter me = 3_m; // operator""m(3) �Լ��� ȣ��˴ϴ�.

	//Gram gr = 3g;
}





