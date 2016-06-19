#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0) : x(a), y(b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }

	Point(const Point& p) { cout << "copy ctor" << endl; }
};

// 함수의 리턴과 임시객체
Point foo()
{
	// NRVO( Named RVO) : 이름 있는 객체도 컴파일러 최적화에 의해
	//					  리턴용 객체 하나만 생성될수 있다는 것을 나타내는 용어
	Point p(1, 2);
	return p; // 이순간 리턴용 임시객체가 생성됩니다.
			  // return Point(p)
			  // 리턴용 임시객체의 수명은 함수 호출표현식이 있는 문장의 끝입니다.
	// 임시객체를 사용한 리턴이 효율적이다.
	// RVO(Return Value Optimization)
//	return Point(1, 2);
}

int main()
{
	Point ret;

	ret = foo();


	cout << "A" << endl;
}





