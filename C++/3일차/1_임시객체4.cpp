#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// �Լ� ���ڿ� �ӽð�ü
void foo(const Point& p)
{

}

int main()
{
//	Point p(1, 1);
//	foo(p);    

	foo(Point(0, 0)); // �ӽð�ü�� ����� ���� ����.
					  // ��, ���ڸ� ������ const ������ �ؾ� �Ѵ�.
					  // �� const ������ �ӽð�ü�� ������ ����.

	cout << "A" << endl;
}





