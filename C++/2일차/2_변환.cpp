// 2_��ȯ
#include <iostream>
using namespace std;
// 52 page

// Point => int   : ��ȯ ������
// int   => Point : ��ȯ ������ 

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// ��ȯ ������ : ���ڰ� �Ѱ��� ������
	//              �ٸ� Ÿ���� ��ü�� ��ȯ�ǰ� �Ѵ�.
	Point(int n) : x(n), y(0) {}


	// ��ȯ ������ �Լ� : ��ü�� �ٸ� Ÿ������ �Ͻ��� ����ȯ �ǰ� �Ѵ�.
	// �Լ� �̸��� ���� Ÿ���� �����Ƿ� ������ ���� Ÿ���� ǥ������ �ʴ´�.
	operator int()
	{
		return x;
	}
};

int main()
{
	Point p1;
	Point p2(1, 2);

	int n = 0;

	n  = p1; // Point => int : p1.operator int()�� ������ �ȴ�.
	p1 = n;  // int => Point : n.operator Point()�� ������ �ȴ�.
			 //					������ n�� ����� Ÿ���� �ƴ� ǥ��Ÿ���̴�.
}






/*
int main()
{
	double d = 3.4;
	int    n = d;  // ?

	Point p(1, 2);
	int n2 = p;    // p.operator int()��� �Լ��� ã�� �˴ϴ�.
}
*/
