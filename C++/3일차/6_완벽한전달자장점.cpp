// 6_�Ϻ�������������
#include <iostream>
#include <vector>
using namespace std;

// �ӽð�ü���� Point Ŭ���� �����ؿ�����
class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	int n = 0;
	vector<Point> v;

	// vector�� ��� �ֱ�1.
//	Point p;
//	v.push_back(p);

	// 2. �ӽð�ü�� ����ؼ� �ֱ�
	//v.push_back( Point(0, 0) );

	// 3. �����ڿ��� ����� ���ڸ� �����ؼ�.. Point ��ü�� vector�� ����� ����.
	v.emplace_back(0, n);


	cout << "A" << endl;
}