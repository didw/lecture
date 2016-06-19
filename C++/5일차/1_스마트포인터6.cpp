#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

// ������� ����Ʈ ������ ���� ��ȣ ������ �߻��ϸ� �޸� ������ ���ü� �ֽ��ϴ�.

struct Node
{
	int data;

	//shared_ptr<Node> next;

	weak_ptr<Node> next; // ��������� ���� ���� �ʴ� ����Ʈ ������

	~Node() { cout << "Node �ı�" << endl; }
};

int main()
{
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);

	p1->next = p2;
	p2->next = p1;
}






