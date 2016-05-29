#include <iostream>
using namespace std;
// 1_new4
// 왜 생성자의 명시적 호출이 필요 한가 ? 41 page

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	// Point 한개를 힙에 만들어 보세요
	Point* p1 = new Point(0,0) ;

	// Point 10개를 힙에 만들어 보세요
	//Point* p2 = new Point[10];

	// 객체의 생성과정중 메모리 할당과 생성자호출을 분리하면 편리할때가 있다.
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// 이미 존재하는 메모리에 생성자를 호출해서 객체로 만든다.
	for (int i = 0;i < 10; i++)
	{
		new( &p3[i] ) Point(0, 0); // placement new사용
	}


}






