// 16_enum
#include <iostream>
using namespace std;

// ������ enum 
// Color��� �̸����̵� ��밡�� - unscoped enum
enum Color { red = 1, green = 2, blue = 3 };

// C++11 scoped enum
//enum class Shape { rect = 1, circle = 2 };

enum class Shape : char { rect = 1, circle = 2 };

int main()
{
	int n = red; // Color::red ��ǥ���� ���� ������ ?
	int red = 30;
	cout << red << endl; // ��������

//	int n2 = rect;        // error
//	int n3 = Shape::rect; // error
	Shape n3 = Shape::rect; // ok..

	int n4 = static_cast<int>(Shape::rect); // ok.. ĳ���� ���
}