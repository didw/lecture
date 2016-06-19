// 3_system_clock2
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;
using namespace std::chrono;

// clock		: 기준 시간으로 부터의 특정 시간을 얻을때 사용하는 클래스
// system_clock : 현재 시간을 얻을때 사용하는 클래스, non monotonic clock
// time_point   : 특정 기간이 지난 duration<>을 보관하는 클래스
//				  ex) 1970년 1월 1일 기준 16880 시간 경과

int main()
{
	// 1. 기준 시각 출력
	system_clock::time_point tp;
	
	cout << (duration_cast<nanoseconds>(tp.time_since_epoch())).count() << endl;

	time_t tm = system_clock::to_time_t(tp);
	string s = ctime(&tm);
	cout << s << endl;

	// 2. 정밀도 출력	
	cout << "rep      : " << typeid(system_clock::rep).name() << endl;
	cout << "period   : " << typeid(system_clock::period).name() << endl;
	cout << "duration : " << typeid(system_clock::duration).name() << endl;
}



