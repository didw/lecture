// 7_���ӻ�����- 216 page

#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	Point() : Point(0,0)   // C++11 ���� ������ ����. - �ٸ� ������ ȣ��
	{
		new(this) Point(0, 0); // placement new�� ������ ȣ��

		Point(0, 0); // �ٸ� ������ ȣ�� �Ҽ� ����.
					// �� ǥ���� ������ ȣ���� �ƴ� �ӽð�ü ���� �Դϴ�.
	}
};

int main()
{
	Point p;
	cout << p.x << endl;
}




