#include <iostream>
using namespace std;


// CRTP : Curiously Recurring Template Pattern

//		�̷��� ������� �Ļ�Ŭ����(�ڽ�Ŭ����)�� �̸��� �θ� ���鶧 ����Ҽ� �ְԵȴ�.
//		

template<typename T> class Singleton
{
public:
	template<typename ... ARG>
	static T& getInstance( ARG&& ... arg )
	{
		static T instance( forward<ARG>(arg)...);
		return instance;
	}
	friend class T;
};

// Ű���嵵 �̱������� �ϰ� �ʹ�.
class Keyboard : public Singleton< Keyboard >
{
private:
	Keyboard(int x, int y) {}
};

int main()
{
	Keyboard& c1 = Keyboard::getInstance(10,20);
}



