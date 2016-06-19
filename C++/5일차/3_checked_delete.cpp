// 3_checked_delete
#include <iostream>
using namespace std;


class Test; // 클래스 전방선언(forward declaration)
			// 전방선언만 있으면 포인터 변수는 만들수 있다.

//Test* p; // incomplete object(불완전 객체) : 전방 선언만 있는 타입의 포인터 
//		   // delete 하면 소멸자가 호출되지 않는다.


// checked delete 라고 불리는 "C++ IDioms"
void foo(Test* p)
{
	enum { type_must_be_complete = sizeof(Test) };

	delete p;
}

class Test
{
	int data;
public:
	Test()  { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
};

int main()
{
	Test* p = new Test;

	foo(p);
}