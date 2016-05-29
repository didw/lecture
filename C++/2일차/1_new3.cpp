// 1_new3
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// 관점의 변환이 필요 합니다.
// malloc : 메모리 할당
// new    : 객체의 생성 => 메모리 할당과 생성자 호출(객체 초기화)

// new Point : 새로운 메모리에 Point 객체를 만들어 달라
// new(&p) Point : 기존의 메모리(&p)에 Point 객체를 만들어 달라.


// 아래 함수를 잘 생각해 보세요
/*
// Placement new라는 함수 입니다.
// C++ 표준에 이미 있습니다.
// 이미 존재하는 객체의 생성자를 호출하기 위한 new 입니다.
void* operator new( size_t sz, void* p)
{
	return p;
}
*/

int main()
{
	Point p;

	//new Point; // 인자가 한개인 operator new() 호출

	new( &p ) Point; // 인자 2개 인 operator new()호출
					// 이미 존재하는 객체 p의 생성자를 호출하는 코드


	//p.Point();  // 생성자의 명시적 호출 ! 될까요 ? error
	p.~Point(); // 소멸자는 명시적 호출가능 ok..
}
// 41 page 입니다. 아주 중요합니다.








