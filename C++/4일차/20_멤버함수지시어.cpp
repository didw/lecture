// 20_����Լ����þ�
// qualifier
#include <iostream>
using namespace std;

class Test
{
public:
	// ��� �Լ� () �ڿ� ������ �ִ°�
	//void foo() const override noexcept  {}
	void goo() &  { cout << "&" << endl; }
	void goo() && { cout << "&&" << endl; }
};

int main()
{
	Test t; 
	t.goo(); // &

	Test().goo();// &&  - �ӽð�ü
}




