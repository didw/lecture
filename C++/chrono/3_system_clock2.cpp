// 3_system_clock2
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;
using namespace std::chrono;

// clock		: ���� �ð����� ������ Ư�� �ð��� ������ ����ϴ� Ŭ����
// system_clock : ���� �ð��� ������ ����ϴ� Ŭ����, non monotonic clock
// time_point   : Ư�� �Ⱓ�� ���� duration<>�� �����ϴ� Ŭ����
//				  ex) 1970�� 1�� 1�� ���� 16880 �ð� ���

int main()
{
	// 1. ���� �ð� ���
	system_clock::time_point tp;
	
	cout << (duration_cast<nanoseconds>(tp.time_since_epoch())).count() << endl;

	time_t tm = system_clock::to_time_t(tp);
	string s = ctime(&tm);
	cout << s << endl;

	// 2. ���е� ���	
	cout << "rep      : " << typeid(system_clock::rep).name() << endl;
	cout << "period   : " << typeid(system_clock::period).name() << endl;
	cout << "duration : " << typeid(system_clock::duration).name() << endl;
}



