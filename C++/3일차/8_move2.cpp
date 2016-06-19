#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test
{
	string data;
public:
	// �����ڿ� �Ҹ���
	Test()  { data = "hello"; }
	~Test() {}

	// ���� �����ڿ� ���Կ�����
	Test(const Test& t)            { cout << "copy" << endl; }
	Test& operator=(const Test& t) { cout << "copy=" << endl; return *this; }

	// Move �����ڿ� Move ���Կ�����
	Test(Test&& t)            { cout << "move" << endl; }
	Test& operator=(Test&& t) { cout << "move=" << endl; return *this; }
};

// swap
template<typename T> void Swap(T& a, T& b)
{
	T temp = move(a);
	a = move(b);
	b = move(temp);
}

int main()
{
	vector<Test> v(10); 

	v.resize(20); // ���� Ű���..



	Test t1, t2;
	Swap(t1, t2);

//	Test t1;
//	Test t2 = t1; // ����
//	t2 = t1; // ����

}

