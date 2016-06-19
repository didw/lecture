#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

class Car
{
public:
	~Car() { cout << "Car ÆÄ±«" << endl; }
};

int main()
{
	shared_ptr<Car> s1(new Car);
	shared_ptr<Car> s2 = s1;
	
	cout << s1.use_count() << endl; // 2

	weak_ptr<Car> w1 = s1;
	cout << s1.use_count() << endl; // 2
}









