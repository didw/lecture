// 1_new
#include <iostream>
using namespace std;
// 38 page

// new �� ��Ȯ�� ���� ��� - 38page
// 1. operator new()��� �Լ��� ����ؼ� �޸� �Ҵ�
// 2. (1)�� �����ϰ� ����� Ÿ���̸� ������ ȣ��
// 3. �޸� �ּҸ� �ش� Ÿ������ ĳ�����ؼ� ����.
class Point
{
	int x, y;
public:
	Point() { cout << "Point()"  << endl; }
	~Point() { cout << "~Point()" << endl; }
};
int main()
{
	// ������ ȣ����� �޸𸮸� �Ҵ��ϴ� ���
	Point* p = static_cast<Point*>(operator new(sizeof(Point)));
	operator delete(p);

//	Point* p = new Point;
//	delete p;
}

