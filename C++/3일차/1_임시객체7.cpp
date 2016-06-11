#include <iostream>
using namespace std;

// 1_�ӽð�ü7
class Base
{
public:
	int value = 10;
};
class Derived : public Base
{
public:
	int value = 20;
};

int main()
{
	Derived d;
	cout << d.value << endl;  // �ڽ��� ��� value

	cout << d.Base::value << endl; // �θ��� value

	cout << (static_cast<Base>(d)).value << endl;
	cout << (static_cast<Base&>(d)).value << endl;

	(static_cast<Base>(d)).value = 30; // error
	(static_cast<Base&>(d)).value = 30; // ok..

}


