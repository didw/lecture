#include <iostream>
#include <string>
using namespace std;

int main()
{
	auto x4 = { 3 };
	auto x5{ 3 };

	cout << typeid(x4).name() << endl;
	cout << typeid(x5).name() << endl;
	

}