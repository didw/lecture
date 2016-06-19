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




	// 복사 생성자 - 깊은 복사나 참조계수등의 기법으로 만듭니다.
	Cat(const Cat& c) 
	{
		cout << "copy" << endl;

		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// Move 생성자 - 소유권 이전의 기법으로 만들게 됩니다.
	// 이렇게 하면 Cat c2(c1) 이 복사 생성자를 호출하지 않고
	// move 생성자를 호출하게 된다!!! - 과거 코드가 동작안함.
	//Cat(Cat& c)  // 이렇게 만들수 없었다...

	// 그래서 move 생성자는 rvalue reference로 만들기로 규칙을 정했다.
	Cat( Cat&& c)
	{			
		cout << "move" << endl;
		
		age = c.age;
		name = c.name;

		c.age = 0;
		c.name = 0;
	}
};

template<typename T>  typename remove_reference<T>::type && xmove(T&& a)  //  T: Cat&   T&& : Cat&
{
	return static_cast<typename remove_reference<T>::type &&>(a);
}

int main()
{
	Cat c1("nabi", 2);
	Cat c2 = c1; // 계속 복사 생성자가 호출되어야 한다.  copy

	Cat c3 = static_cast<Cat&&>(c1); // move 

	Cat c4 = xmove(c2); // move

	Cat c5 = move(c3); // move

}





