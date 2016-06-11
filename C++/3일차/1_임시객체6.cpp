#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }

	Point(const Point& p) { cout << "copy ctor" << endl; }
};

// 함수의 리턴과 임시객체

Point p(1, 1); // 전역변수


//Point foo()  // 값리턴 : 임시객체를 리턴한다.

Point& foo()   // 참조리턴 : 임시객체를 만들지 말라는 의미
{			   //            단, 지역객체를 참조리턴하면 안된다.
	return p;
}

int main()
{
	foo().x = 10; // error. 임시객체는 lvalue가 될수 없다.
				  // 단, 참조리턴이면 ok..

	cout << "A" << endl;
}





