// 8_STL�ݺ���

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

// slist�� Node�� ����Ű�� ����Ʈ �����Ϳ� ������ ��ü(�ݺ���, iterator)

template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	inline slist_iterator(Node<T>* p = 0) : current(p) {}

	// ++�� �̵��ϰ� *�� ���� ������ �ְ�
	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T& operator*() { return current->data; }

	inline bool operator==(const slist_iterator& it) { return current == it.current; }
	inline bool operator!=(const slist_iterator& it) { return current != it.current; }
};












template<typename T> class slist
{
	Node<T>* head;
public:
	slist() : head(0) {}

	void push_front(const T& a) { head = new Node<T>(a, head); }


	// ��� �����̳� �����ڴ� �ڽ��� �ݺ��� �̸��� ���ϵ� ���·� �ܺο� �����Ѵ�.
	typedef slist_iterator<T> iterator;

	// ��� �����̳� �����ڴ� �ڽ��� ���۰� ������ ������ ����Ű�� �ݺ��ڸ� �����ϴ�
	// �Լ� �� �����ؾ� �Ѵ�.
	iterator begin() { return iterator(head); }
	iterator end()   { return iterator(0); }
};




int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40); 

	//slist_iterator<int> p = s.begin();

	slist<int>::iterator p = s.begin();

	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}




