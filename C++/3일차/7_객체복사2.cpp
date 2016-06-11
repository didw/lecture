// 7_��ü���� - 57 page

#include <iostream>
using namespace std;

class Cat
{
	char* name;
	int   age;
public:
	Cat(const char* s, int a) : age(a)
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
	}
	~Cat() { delete[] name; }

	// ���� ����� ������ ���� ������ - 60 page �׸�.
	Cat(const Cat& c)
	{
		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}
};




int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;       
}


