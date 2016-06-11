// 5_일관된초기화 - 205 page
#include <iostream>
using namespace std;

struct Point { int x, y; };

class Complex
{
	int re, im;
public:
	Complex(int a = 0, int b = 0) : re(a), im(b) {}
};
/*
int main()
{
	int n1 = 10;
	int n2(10);
	int ar[3] = { 1,2,3 };
	Point p = { 1,2 };
	Complex c(1, 2);
}
*/
int main()
{
	// C++11 : Uniform Initialize 문법 - 모든 타입을 하나의 초기화 방법으로 
	/*
	// copy initialize
	int    n1{ 10 };
	int    n2{ 10 };
	int ar[3]{ 1,2,3 };
	Point   p{ 1,2 };
	Complex c{ 1, 2 };
	*/

	// list initialize
	int    n1 = { 10 };
	int    n2 = { 10 };
	int ar[3] = { 1,2,3 };
	Point   p = { 1,2 };
	Complex c = { 1, 2 };
}




