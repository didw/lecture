#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// duration ���� : Ư�� ������ ����(tick count)�� ǥ���ϴ� �ڷᱸ��
//				  10�� => 1���� 10��
//					   => 1/1000���� 10000��..

int main()
{
	// 1. duration ���
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


	// ��Ģ ����(+, -,*, /, +=, -=, *=, /=)
	cm += Meter(1);

	cout << km.count() << endl;
	cout << me.count() << endl;
	cout << cm.count() << endl;


	// 3. casting.
	Meter me2(560);

	cout << duration_cast<KiloMeter>(me2).count() << endl;
	cout << floor<KiloMeter>(me2).count() << endl; // ����
	cout << ceil<KiloMeter>(me2).count() << endl;  // �ø�
	cout << round<KiloMeter>(me2).count() << endl; // �ݿø�
	cout << abs(me2).count() << endl;
}
