// 6_함수객체
#include <iostream>
using namespace std;


// 함수 객체 : ()연산자를 재정의 해서 함수 처럼 사용가능한 객체
//			Functor 라고도 부른다.!
//			() 연산자 함수는 대부분 상수 함수로 만들게 된다.

class Plus
{
public:
	int operator()(int a, int b) const
	{
		return a + b;
	}
};


int main()
{
	Plus p;
	int n = p(1, 2); // ?
	cout << n << endl; // 3

	// a + b; // a.operator+ ( b )
	// a - b; // a.operator- ( b ) 
	// a();   // a.operator()()
	// a(1,2);// a.operator()(1,2)

}// 26 page

