#include <chrono>
#include <thread>
#include <iostream>
using namespace std;
using namespace chrono;

int main()
{
	cout << "A" << endl;
	this_thread::sleep_for(1s+10ms);

	cout << "B" << endl;
	this_thread::sleep_until(system_clock::now() + seconds(10));

	cout << "C" << endl;
}