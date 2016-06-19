// 3_checked_delete
#include <iostream>
using namespace std;


class Test; // Ŭ���� ���漱��(forward declaration)
			// ���漱�� ������ ������ ������ ����� �ִ�.

//Test* p; // incomplete object(�ҿ��� ��ü) : ���� ���� �ִ� Ÿ���� ������ 
//		   // delete �ϸ� �Ҹ��ڰ� ȣ����� �ʴ´�.


// checked delete ��� �Ҹ��� "C++ IDioms"
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