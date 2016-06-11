// 18_사용자정의상수 - 225
#include <iostream>
#include <string>
#include <complex>
#include <chrono>
using namespace std::chrono;
using namespace std;

void foo(string s)      { cout << "string" << endl; }   // 1
void foo(const char* s) { cout << "char*" << endl; }    // 2

int main()
{
	foo("hello");// 2
	foo("hello"s);// 1

	complex<int> c1(1, 2);
	complex<int> c2(2);
	complex<int> c3(2i);
	cout << c1 << endl;
	cout << c2 << endl;
	cout << c3 << endl;

	minutes k = 3min;
	seconds sec = k; 
	cout << sec.count() << endl; // 180

}





