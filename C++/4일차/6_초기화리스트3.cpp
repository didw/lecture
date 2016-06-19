#include <iostream>
using namespace std;

// initializer_list는 생성자 인자로 널리 활용됩니다.

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

//	Point p1(1, 1); // 1 없다면 error
//	Point p2{ 1,1 };// 2 없다면 1
	
	Point p3({ 1, 1 }); // 2 없다면 error 이 지만
					// {1, 1} 가 변환 생성자에 의해서 Point(1,1)의 임시객체생성
					// C++11 부터는 생성자 인자가 2개 이상이 있어도 변환가능
					// {1,1} => int 2개인 생성자를 사용해서 변환


//	Point p4 = { 1,1 }; // p2와 동일.
//	Point p5(1,2,3); // error.

//	Point p6{ 1, 2,3 }; // ok...

	// 이제 STL은 아래 처럼 사용할수 있게 됩니다.
	//vector<int> v = { 1,2,3,4,5,6,7 };
}





