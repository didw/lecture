#include <iostream>
using namespace std;

template<typename T> class stack
{
public:

	// T는 user type일수 있으므로 최적화 하자.

	// 1. call by value 보다는 const &가 좋다.
	// void push(T a) {}
	void push(const T& a) {}

	// 2. pop이 제거와 리턴을 동시에 하면 참조리턴을 할수 없다.
	//   즉, 항상 값으로 리턴해야 한다. 임시객체가 생성된다.
	//T    pop() {}

	// 제거와 리턴을 분리하자.
	T& top() { }   // 리턴만.. 제거하지 말자!!
	void pop() {}  // 제거만.. 리턴하지 말자
};

// 템플릿 기반 컨테이너 설계시 제거와 리턴을 분리하는 이유
// 1. 임시객체를 없애기 위해
// 2. 예외 안정성의 강력 보장을 위해서.. - 5주차에 다루게 됩니다.

// STL의 대부분의 클래스는 제거와 리턴을 동시에 하는 함수가 없습니다.

int main()
{
	stack<Rect> s;
	stack<Rect*> s;
	s.top();
	s.pop();
}



