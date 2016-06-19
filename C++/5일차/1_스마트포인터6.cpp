#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

// 참조계수 스마트 포인터 사용시 상호 참조가 발생하면 메모리 누수가 나올수 있습니다.

struct Node
{
	int data;

	//shared_ptr<Node> next;

	weak_ptr<Node> next; // 참조계수가 증가 하지 않는 스마트 포인터

	~Node() { cout << "Node 파괴" << endl; }
};

int main()
{
	shared_ptr<Node> p1(new Node);
	shared_ptr<Node> p2(new Node);

	p1->next = p2;
	p2->next = p1;
}






