#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// 함수 인자와 임시객체
void foo(const Point& p)
{

}

int main()
{
//	Point p(1, 1);
//	foo(p);    

	foo(Point(0, 0)); // 임시객체를 사용한 인자 전달.
					  // 단, 인자를 받을때 const 참조로 해야 한다.
					  // 비 const 참조는 임시객체를 담을수 없다.

	cout << "A" << endl;
}





