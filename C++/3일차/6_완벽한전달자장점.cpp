// 6_완벽한전달자장점
#include <iostream>
#include <vector>
using namespace std;

// 임시객체에서 Point 클래스 복사해오세요
class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	int n = 0;
	vector<Point> v;

	// vector에 요소 넣기1.
//	Point p;
//	v.push_back(p);

	// 2. 임시객체를 사용해서 넣기
	//v.push_back( Point(0, 0) );

	// 3. 생성자에서 사용할 인자를 전달해서.. Point 자체를 vector가 만들게 하자.
	v.emplace_back(0, n);


	cout << "A" << endl;
}