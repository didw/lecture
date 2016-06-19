#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// steady_clock : monotonic clock, 컴퓨터 부팅후 시간
//				  
int main()
{
	steady_clock::time_point tp1 = steady_clock::now();
	
	steady_clock::time_point tp2;

	seconds d1 = duration_cast<seconds>(tp1.time_since_epoch());
	cout << d1.count() << endl;

	seconds d2 = duration_cast<seconds>(tp2.time_since_epoch());
	cout << d2.count() << endl;
}