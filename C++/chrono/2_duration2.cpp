#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

int main()
{
	// 1. predefined typedef
	hours		 h(1);     // typedef duration<int, ratio<3600,1>> hours;
	minutes      m  = h;
	seconds      s  = h;
	milliseconds ms = h;
	microseconds us = h;
	nanoseconds  ns = h;

	cout << h.count() << endl;
	cout << m.count() << endl;
	cout << s.count() << endl;
	cout << ms.count() << endl;
	cout << us.count() << endl;
	cout << ns.count() << endl;

	// 2. literals( h, min, s, ms, us, ns )
	seconds sec = 1min;

	sec = 1min + 3s;
	sec += 40s;
	cout << sec.count() << endl;

	seconds sec2 = 1min + 3s;
	cout << sec2.count() << endl;
}