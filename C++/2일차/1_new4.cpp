#include <iostream>
using namespace std;
// 1_new4
// �� �������� ����� ȣ���� �ʿ� �Ѱ� ? 41 page

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	// Point �Ѱ��� ���� ����� ������
	Point* p1 = new Point(0,0) ;

	// Point 10���� ���� ����� ������
	//Point* p2 = new Point[10];

	// ��ü�� ���������� �޸� �Ҵ�� ������ȣ���� �и��ϸ� ���Ҷ��� �ִ�.
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));

	// �̹� �����ϴ� �޸𸮿� �����ڸ� ȣ���ؼ� ��ü�� �����.
	for (int i = 0;i < 10; i++)
	{
		new( &p3[i] ) Point(0, 0); // placement new���
	}


}






