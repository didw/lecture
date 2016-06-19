// 7_STL컨테이너

#include <iostream>
using namespace std;

// 싱글리스트를 생각해 봅시다.
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
	s.push_front(40); // 이 때의 메모리 그림이 175 page 입니다.
}




