#include <iostream>
using namespace std;


class Cursor
{
public:
	// 싱글톤의 기본 : 유일한 객체를 리턴하는 static 멤버 함수
	static Cursor& getInstance()
	{
		static Cursor instance;
		return instance;
	}
};

int main()
{
	Cursor& c1 = Cursor::getInstance();
}



