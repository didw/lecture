// 2_변환
#include <iostream>
using namespace std;
// 52 page

// Point => int   : 변환 연산자
// int   => Point : 변환 생성자 

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 변환 생성자 : 인자가 한개인 생성자
	//              다른 타입이 객체로 변환되게 한다.
	Point(int n) : x(n), y(0) {}


	// 변환 연산자 함수 : 객체를 다른 타입으로 암시적 형변환 되게 한다.
	// 함수 이름에 리턴 타입이 있으므로 별도로 리턴 타입을 표기하지 않는다.
	operator int()
	{
		return x;
	}
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n = 0;

	n  = p1; // Point => int : p1.operator int()가 있으면 된다.
	p1 = n;  // int => Point : n.operator Point()가 있으면 된다.
			 //					하지만 n은 사용자 타입이 아닌 표준타입이다.
}






/*
int main()
{
	double d = 3.4;
	int    n = d;  // ?

	Point p(1, 2);
	int n2 = p;    // p.operator int()라는 함수를 찾게 됩니다.
}
*/
