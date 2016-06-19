// 7_객체복사 - 57 page

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




	// 아래 복사 생성자 잘생각해 보세요 - 어렵습니다.
	// 소유권 이전의 기법을 사용하는 복사 생성자 - 1990년대 말에 등장한 기법.
	// C++11 부터는 Move 생성자라고 부릅니다.
	Cat( Cat& c) // 주의 !! const가 없습니다.
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


