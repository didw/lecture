// 16_enum
#include <iostream>
using namespace std;

// 기존의 enum 
// Color라는 이름없이도 사용가능 - unscoped enum
enum Color { red = 1, green = 2, blue = 3 };

// C++11 scoped enum
//enum class Shape { rect = 1, circle = 2 };

enum class Shape : char { rect = 1, circle = 2 };

int main()
{
	int n = red; // Color::red 이표현이 맞지 않을까 ?
	int red = 30;
	cout << red << endl; // 지역변수

//	int n2 = rect;        // error
//	int n3 = Shape::rect; // error
	Shape n3 = Shape::rect; // ok..

	int n4 = static_cast<int>(Shape::rect); // ok.. 캐스팅 허용
}