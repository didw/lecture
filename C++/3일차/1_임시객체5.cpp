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
Point foo()
{
	// NRVO( Named RVO) : �̸� �ִ� ��ü�� �����Ϸ� ����ȭ�� ����
	//					  ���Ͽ� ��ü �ϳ��� �����ɼ� �ִٴ� ���� ��Ÿ���� ���
	Point p(1, 2);
	return p; // �̼��� ���Ͽ� �ӽð�ü�� �����˴ϴ�.
			  // return Point(p)
			  // ���Ͽ� �ӽð�ü�� ������ �Լ� ȣ��ǥ������ �ִ� ������ ���Դϴ�.
	// �ӽð�ü�� ����� ������ ȿ�����̴�.
	// RVO(Return Value Optimization)
//	return Point(1, 2);
}

int main()
{
	Point ret;

	ret = foo();


	cout << "A" << endl;
}





