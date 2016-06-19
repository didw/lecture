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




	// �Ʒ� ���� ������ �߻����� ������ - ��ƽ��ϴ�.
	// ������ ������ ����� ����ϴ� ���� ������ - 1990��� ���� ������ ���.
	// C++11 ���ʹ� Move �����ڶ�� �θ��ϴ�.
	Cat( Cat& c) // ���� !! const�� �����ϴ�.
	{
		age  = c.age;
		name = c.name;
	
		c.age = 0;
		c.name = 0;
	}
};




int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;
}


