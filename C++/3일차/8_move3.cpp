#include <iostream>
#include <string>
#include <vector>
using namespace std;


// ���� �����ڿ����� ��� ����� ����� �ű��
// move �����ڿ����� ��� ����� move�� �ű��.
// 
class Test
{
	string data;
public:
	// �����ڿ� �Ҹ���
	Test() { data = "hello"; }
	~Test() {}

	// ���� �����ڿ� ���Կ�����
	Test(const Test& t)   : data(t.data) { cout << "copy" << endl; }
	Test& operator=(const Test& t)       { data = t.data; cout << "copy=" << endl; return *this; }

	// Move �����ڿ� Move ���Կ�����
	Test(Test&& t) : data(move(t.data))  { cout << "move" << endl; }

	Test& operator=(Test&& t)            { data = move(t.data); cout << "move=" << endl; return *this; }
};



int main()
{

}

