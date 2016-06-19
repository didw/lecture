// 5_clock_property
#include <chrono>
#include <string>
#include <iostream>
#include <typeinfo>
using namespace std;
using namespace std::chrono;

template<typename T> void print_clock_property()
{
	cout << '\n';
	cout << "\t internal name     : " << typeid(T).name() << endl;
	cout << "\t monotonic(steady) : " << boolalpha << T::is_steady << endl;
	cout << "\t represent type    : " << typeid(typename T::rep).name() << endl;
	cout << "\t period            : " << typeid(typename T::period).name() << endl;
	cout << "\t duration          : " << typeid(typename T::duration).name() << endl;

	typename T::duration pre(1);

	cout << "\t precision         : " << (duration_cast<nanoseconds>(pre)).count() << " nanoseconds" << endl;
	cout << '\n';
}
int main()
{
	cout << "[ system_clock ]" << endl;
	print_clock_property<system_clock>();

	cout << "[ steady_clock ]" << endl;
	print_clock_property<steady_clock>();

	cout << "[ high_resolution_clock ]" << endl;
	print_clock_property<high_resolution_clock>();
}


