// 20_멤버함수지시어
// qualifier
#include <iostream>
using namespace std;

class Test
{
public:
	// 멤버 함수 () 뒤에 붙을수 있는것
	//void foo() const override noexcept  {}
	void goo() &  { cout << "&" << endl; }
	void goo() && { cout << "&&" << endl; }
};

int main()
{
	Test t; 
	t.goo(); // &

	Test().goo();// &&  - 임시객체
}




