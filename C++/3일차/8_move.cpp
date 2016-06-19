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




	// ���� ������ - ���� ���糪 ����������� ������� ����ϴ�.
	Cat(const Cat& c) 
	{
		cout << "copy" << endl;

		age = c.age;

		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
	}

	// Move ������ - ������ ������ ������� ����� �˴ϴ�.
	// �̷��� �ϸ� Cat c2(c1) �� ���� �����ڸ� ȣ������ �ʰ�
	// move �����ڸ� ȣ���ϰ� �ȴ�!!! - ���� �ڵ尡 ���۾���.
	//Cat(Cat& c)  // �̷��� ����� ������...

	// �׷��� move �����ڴ� rvalue reference�� ������ ��Ģ�� ���ߴ�.
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
	Cat c2 = c1; // ��� ���� �����ڰ� ȣ��Ǿ�� �Ѵ�.  copy

	Cat c3 = static_cast<Cat&&>(c1); // move 

	Cat c4 = xmove(c2); // move

	Cat c5 = move(c3); // move

}





