// 2_��ȯ3
#include <iostream>
#include <memory>
using namespace std;

class Test
{
	int value;
public:
	explicit Test(int n) : value(n) {}
};

int main()
{
	// �Ʒ� 2���� �������� ������ ������
	Test t1(5);  // ���ڰ� �Ѱ��� ������ ȣ��
	//Test t2 = 5; // 1. 5�� ��ȯ�����ڸ� ����ؼ� Test�� �ӽð�ü ����
				 // 2. Test �ӽð�ü�� ���� �����ڸ� ����ؼ� t2�� ���� 

	// C++ ǥ���� ����Ʈ ������ - <memory> ���..
	shared_ptr<int> p1 = new int;

	shared_ptr<int> p2( new int );

	// �ȵ���̵� �����ӿ�ũ �ҽ��� String Ŭ������ �����ڵ� explicit �Դϴ�.

	String s1 = "hello";//error
	String s2("hello"); // ok
}






