#include <iostream>
using namespace std;


// CRTP : Curiously Recurring Template Pattern

//		미래에 만들어진 파생클래스(자식클래스)의 이름을 부모 만들때 사용할수 있게된다.
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

// 키보드도 싱글톤으로 하고 싶다.
class Keyboard : public Singleton< Keyboard >
{
private:
	Keyboard(int x, int y) {}
};

int main()
{
	Keyboard& c1 = Keyboard::getInstance(10,20);
}



