// 7_°´Ã¼º¹»ç - 57 page

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
};
int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1;       // runtime error  58page±×¸². ¾èÀº º¹»ç
}


