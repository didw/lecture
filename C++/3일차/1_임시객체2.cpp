#include <iostream>
using namespace std;

// 핵심
// 1. 임시객체를 명시적으로 만드는 법.
// 2. 임시객체의 수명 : 문장의 끝
// 3. 임시객체는 lvalue가 될수 없다.
// 4. 임시객체는 주소연산자를 사용할수 없다.

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point()                                 { cout << "~Point()" << endl; }
};

int main()
{
//	Point p1;

//	Point(1, 1); // 사용자가 직접 만드는 임시객체. 클래스이름(). 이름 없는 객체
				 // 문장의 끝(;)에서 파괴 된다.

	Point(0, 0), cout << "X" << endl;

	//----------------------------------
	Point p2;
	p2.x = 10; // ok..
	
//	Point(0, 0).x = 20; // ?? 될까요 ?  임시객체는 lvalue가 될수 없다.

	cout << &Point(0, 0) << endl; // 임시객체 주소 얻기

	Point* p = &Point(0, 0);


	cout << "A" << endl;
}





