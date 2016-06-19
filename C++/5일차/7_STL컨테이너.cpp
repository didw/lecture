// 7_STL�����̳�

#include <iostream>
using namespace std;

// �̱۸���Ʈ�� ������ ���ô�.
template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}

	void push_front(const T& a) { head = new Node<T>(a, head); }
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); // �� ���� �޸� �׸��� 175 page �Դϴ�.
}




