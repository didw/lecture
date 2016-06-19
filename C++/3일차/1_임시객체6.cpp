#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }

	Point(const Point& p) { cout << "copy ctor" << endl; }
};

// �Լ��� ���ϰ� �ӽð�ü

Point p(1, 1); // ��������


//Point foo()  // ������ : �ӽð�ü�� �����Ѵ�.

Point& foo()   // �������� : �ӽð�ü�� ������ ����� �ǹ�
{			   //            ��, ������ü�� ���������ϸ� �ȵȴ�.
	return p;
}

int main()
{
	foo().x = 10; // error. �ӽð�ü�� lvalue�� �ɼ� ����.
				  // ��, ���������̸� ok..

	cout << "A" << endl;
}





