// 8_STL반복자

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

// slist의 Node를 가르키는 스마트 포인터와 유사한 객체(반복자, iterator)

template<typename T> class slist_iterator
{
	Node<T>* current;
public:
	inline slist_iterator(Node<T>* p = 0) : current(p) {}

	// ++로 이동하고 *로 값을 꺼낼수 있게
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


	// 모든 컨테이너 설계자는 자신의 반복자 이름을 통일된 형태로 외부에 노출한다.
	typedef slist_iterator<T> iterator;

	// 모든 컨테이너 설계자는 자신의 시작과 마지막 다음을 가르키는 반복자를 리턴하는
	// 함수 를 제공해야 한다.
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




