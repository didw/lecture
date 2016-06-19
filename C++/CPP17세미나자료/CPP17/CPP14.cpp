#include <iostream>
#include <vector>
using namespace std;

struct Point
{
	int x, y;

	Point(int a, int& b, int c) : x(a), y(b) { cout << "ctor" << endl; }
	~Point() { cout << "dtor" << endl; }
	Point(const Point&) { cout << "copy" << endl; }
	Point(Point&&)      { cout << "move" << endl; }

	Point& operator=(const Point&&) { cout << "copy=" << endl; return *this; }
	Point& operator=(Point&&)       { cout << "move=" << endl; return *this; }
};

// C++14 move¿Í perfect forwarding
int main()
{
	vector<Point> v;

//	Point p(1, 2); //
//	v.push_back(p);


//	Point p(1, 2); //
//	v.push_back(move(p));

//	v.push_back(Point(1, 2));
	int n = 10;

	v.emplace_back(1, n, 3);


	cout << "A" << endl;
}






