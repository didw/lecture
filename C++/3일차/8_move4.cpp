#include <iostream>
#include <string>
#include <vector>
using namespace std;




// �ټ��� STL ���̺귯���� move �����ڿ� ���ܰ� �������� move�����ڸ�����մϴ�.
// move �迭 �Լ��� ���鶧 �� noexcept �� �ٿ� �ּ���..

class Test
{
	string data;
public:
	Test() { data = "hello"; }
	~Test() {}
	Test(const Test& t) : data(t.data) { cout << "copy" << endl; }
	Test& operator=(const Test& t) { data = t.data; cout << "copy=" << endl; return *this; }


	Test(Test&& t) noexcept : data(move(t.data)) { cout << "move" << endl; }
	Test& operator=(Test&& t) noexcept { data = move(t.data); cout << "move=" << endl; return *this; }
};

int main()
{
	Test t1;
	Test t2 = t1; // copy
	Test t3 = move(t1); // move ������ �غ�����..

	Test t4 = move_if_noexcept(t2); // move�����ڿ� ���ܰ� �������� move���
									// �߿��� ����.
					
}

