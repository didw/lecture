// 1_new
#include <iostream>
using namespace std;
// 38 page

// new 의 정확한 동작 방식 - 38page
// 1. operator new()라는 함수를 사용해서 메모리 할당
// 2. (1)이 성공하고 사용자 타입이면 생성자 호출
// 3. 메모리 주소를 해당 타입으로 캐스팅해서 리턴.
class Point
{
	int x, y;
public:
	Point() { cout << "Point()"  << endl; }
	~Point() { cout << "~Point()" << endl; }
};
int main()
{
	// 생성자 호출없이 메모리만 할당하는 방법
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));
	operator delete(p);

//	Point* p = new Point;
//	delete p;
}

