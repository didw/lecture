#include <iostream>
using namespace std;


class Cursor
{
public:
	// �̱����� �⺻ : ������ ��ü�� �����ϴ� static ��� �Լ�
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



