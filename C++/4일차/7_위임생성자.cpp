// 7_위임생성자- 216 page

#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	Point() : Point(0,0)   // C++11 위임 생성자 문법. - 다른 생성자 호출
	{
		new(this) Point(0, 0); // placement new로 생성자 호출

		Point(0, 0); // 다른 생성자 호출 할수 없다.
					// 이 표현은 생성자 호출이 아닌 임시객체 생성 입니다.
	}
};

int main()
{
	Point p;
	cout << p.x << endl;
}




