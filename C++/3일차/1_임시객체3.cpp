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
//	Point& r2 = Point(0, 0);	// error. �ӽð�ü�� �����Ҽ� ����.

	const Point& r3 = Point(0, 0); // ok.. ��� ������ ������ �ִ�.
									// �̰�� �ӽð�ü�� �̸��� ����� �ǰ�(r3)
									// ������ r3�� ������ ����ȴ�.

	r3.x = 10; // ���� lvalue�ü��� ������ r3�� ��� �̹Ƿ� error

	// ��, const ������ ����ų�� ������ ������� ����� �ȴ�.!!

	// C++11�� �ӽð�ü�� ����Ű�� ���� ����.
	Point&& r4 = Point(0, 0);

	cout << "A" << endl;
}




//int& r = 10; //error
//const int& r = 10; //ok.



