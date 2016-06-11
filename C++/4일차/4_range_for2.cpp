// 4_range_for
#include <iostream>
#include <list>
#include <type_traits>
using namespace std;

struct Point3D
{
	int x, y, z;

	Point3D(int a, int b, int c) : x(a), y(b), z(c) {}
};

int* begin(Point3D& p) { return &(p.x); }
int* end(Point3D& p)   { return &(p.z) + 1; }

int main()
{
	Point3D p(1, 2, 3);

	for (auto n : p)       // �ɱ�� ? �ǰ� �Ϸ��� ??
		cout << n << endl;
}










