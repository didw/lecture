#include <iostream>
using namespace std;

// C++ǥ�ؿ� �̹� ������� ��� ����Ʈ �����Ͱ� �ֽ��ϴ�.
#include <memory>

int main()
{
	//shared_ptr<int> p1 = new int; // error

	shared_ptr<int> p1(new int); // ok.. explicit ������

	shared_ptr<int> p2 = p1; // �̼��� ��������� ���� �մϴ�.
}