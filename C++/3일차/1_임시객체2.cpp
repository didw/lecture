#include <iostream>
using namespace std;

// �ٽ�
// 1. �ӽð�ü�� ��������� ����� ��.
// 2. �ӽð�ü�� ���� : ������ ��
// 3. �ӽð�ü�� lvalue�� �ɼ� ����.
// 4. �ӽð�ü�� �ּҿ����ڸ� ����Ҽ� ����.

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point()                                 { cout << "~Point()" << endl; }
};

int main()
{
//	Point p1;

//	Point(1, 1); // ����ڰ� ���� ����� �ӽð�ü. Ŭ�����̸�(). �̸� ���� ��ü
				 // ������ ��(;)���� �ı� �ȴ�.

	Point(0, 0), cout << "X" << endl;

	//----------------------------------
	Point p2;
	p2.x = 10; // ok..
	
//	Point(0, 0).x = 20; // ?? �ɱ�� ?  �ӽð�ü�� lvalue�� �ɼ� ����.

	cout << &Point(0, 0) << endl; // �ӽð�ü �ּ� ���

	Point* p = &Point(0, 0);


	cout << "A" << endl;
}





