#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// duration 정의 : 특정 단위의 갯수(tick count)를 표현하는 자료구조
//				  10초 => 1초의 10개
//					   => 1/1000초의 10000개..

int main()
{
	// 1. duration 사용
	duration<int, ratio<1, 100>>  d1(2); // 1/100 * 2
	duration<int, ratio<1, 1000>> d2(d1); 

	cout << d2.count() << endl;


	// 2. predefined SI(kilo, centi...)
	using Meter		 = duration<int, ratio<1, 1>>;
	using KiloMeter	 = duration<int, kilo>;
	using CentiMeter = duration<int, centi>;

	Meter     me(5000);


	CentiMeter cm = me;	// Meter => CentiMeter, Implicit Conversion
	
	// KiloMeter km = me; // error

	KiloMeter km = duration_cast<KiloMeter>(me); // ok.. explicit conversion


	// 사칙 연산(+, -,*, /, +=, -=, *=, /=)
	cm += Meter(1);

	cout << km.count() << endl;
	cout << me.count() << endl;
	cout << cm.count() << endl;


	// 3. casting.
	Meter me2(560);

	cout << duration_cast<KiloMeter>(me2).count() << endl;
	cout << floor<KiloMeter>(me2).count() << endl; // 버림
	cout << ceil<KiloMeter>(me2).count() << endl;  // 올림
	cout << round<KiloMeter>(me2).count() << endl; // 반올림
	cout << abs(me2).count() << endl;
}
