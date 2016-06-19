// 1_new3
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// ������ ��ȯ�� �ʿ� �մϴ�.
// malloc : �޸� �Ҵ�
// new    : ��ü�� ���� => �޸� �Ҵ�� ������ ȣ��(��ü �ʱ�ȭ)

// new Point : ���ο� �޸𸮿� Point ��ü�� ����� �޶�
// new(&p) Point : ������ �޸�(&p)�� Point ��ü�� ����� �޶�.


// �Ʒ� �Լ��� �� ������ ������
/*
// Placement new��� �Լ� �Դϴ�.
// C++ ǥ�ؿ� �̹� �ֽ��ϴ�.
// �̹� �����ϴ� ��ü�� �����ڸ� ȣ���ϱ� ���� new �Դϴ�.
void* operator new( size_t sz, void* p)
{
	return p;
}
*/

int main()
{
	Point p;

	//new Point; // ���ڰ� �Ѱ��� operator new() ȣ��

	new( &p ) Point; // ���� 2�� �� operator new()ȣ��
					// �̹� �����ϴ� ��ü p�� �����ڸ� ȣ���ϴ� �ڵ�


	//p.Point();  // �������� ����� ȣ�� ! �ɱ�� ? error
	p.~Point(); // �Ҹ��ڴ� ����� ȣ�Ⱑ�� ok..
}
// 41 page �Դϴ�. ���� �߿��մϴ�.








