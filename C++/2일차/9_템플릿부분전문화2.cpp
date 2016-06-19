// 9_템플릿부분전문화2

#include <iostream>
using namespace std;

template<typename T, typename U> class Pair
{
public:
	void foo() { cout << "T,U" << endl; }
};

// 부분 전문화 할때 템플릿 인자의 갯수가 primary template과 다를수도 있습니다.
template<typename T> class Pair<short, T>
{
public:
	void foo() { cout << "short, T" << endl; }
};

template<typename T> class Pair<T, T>
{
public:
	void foo() { cout << "T, T" << endl; }
};

template<typename T, typename U> class Pair<T*, U>
{
public:
	void foo() { cout << "T*, U" << endl; }
};

int main()
{
	Pair<int,    double> p1; p1.foo();
	Pair<short,  double> p2; p2.foo();
	Pair<double, double> p3; p3.foo(); // 두개의 타입을 같을때
	Pair<char*,  double> p4; p4.foo(); // 1번째가 포인터이고, 2번째 포인터가 아닌경우
}





