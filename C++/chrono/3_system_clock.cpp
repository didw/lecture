#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;
using namespace std::chrono;

// system_clock : ���� �ð��� ������ ����ϴ� Ŭ����, non monotonic clock
// time_point   : �ð��� �������� duration<>�� �����ϴ� Ŭ����
//				  ex) 1970�� 1�� 1�� ���� 16880 �ð� ���

int main()
{
	// 1. ���� �ð��� ��� ���
	system_clock::time_point tp = system_clock::now();


	// 2. time_point => duration ����... ���е��� �������� ��� ����� ĳ���� �ʿ�..
	nanoseconds nanosec = tp.time_since_epoch();
	seconds     sec     = duration_cast<seconds>(tp.time_since_epoch());
	
	cout << nanosec.count() << endl;
	cout << sec.count() << endl;

	using days = duration<int, ratio<60 * 60 * 24>>;
	cout << (duration_cast<days>(tp.time_since_epoch())).count() << endl;


	// 3. time_point => Į���� ������ ��¥�� �����ϱ�
	time_t t = system_clock::to_time_t(tp); // 1. time_point => struct time_t
	string s = ctime(&t);					// 2. struct time_t => char*
	cout << s << endl;
}



