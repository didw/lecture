#include <iostream>
using namespace std;

// initializer_list�� ������ ���ڷ� �θ� Ȱ��˴ϴ�.

class Point
{
	int x, y;
public:
	explicit Point(int a, int b)            { cout << "int, int" << endl; }		// 1
//	Point(initializer_list<int> e) { cout << "initializer_list" << endl; }// 2
};
void foo(int a, int b) {}

int main()
{
//	foo({ 1,2 }); // error

//	Point p1(1, 1); // 1 ���ٸ� error
//	Point p2{ 1,1 };// 2 ���ٸ� 1
	
	Point p3({ 1, 1 }); // 2 ���ٸ� error �� ����
					// {1, 1} �� ��ȯ �����ڿ� ���ؼ� Point(1,1)�� �ӽð�ü����
					// C++11 ���ʹ� ������ ���ڰ� 2�� �̻��� �־ ��ȯ����
					// {1,1} => int 2���� �����ڸ� ����ؼ� ��ȯ


//	Point p4 = { 1,1 }; // p2�� ����.
//	Point p5(1,2,3); // error.

//	Point p6{ 1, 2,3 }; // ok...

	// ���� STL�� �Ʒ� ó�� ����Ҽ� �ְ� �˴ϴ�.
	//vector<int> v = { 1,2,3,4,5,6,7 };
}





