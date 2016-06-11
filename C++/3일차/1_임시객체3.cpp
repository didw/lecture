#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
//	Point p1(0, 0);
//	Point& r1 = p1;				// ok
//	Point& r2 = Point(0, 0);	// error. 임시객체는 참조할수 없다.

	const Point& r3 = Point(0, 0); // ok.. 상수 참조에 담을수 있다.
									// 이경우 임시객체에 이름이 생기게 되고(r3)
									// 수명이 r3이 수명을 연장된다.

	r3.x = 10; // 이제 lvalue올수는 있지만 r3가 상수 이므로 error

	// 즉, const 참조로 가르킬수 있지만 상수성이 생기게 된다.!!

	// C++11의 임시객체를 가르키는 참조 문법.
	Point&& r4 = Point(0, 0);

	cout << "A" << endl;
}




//int& r = 10; //error
//const int& r = 10; //ok.



