#include <iostream>
using namespace std;

// 1. 구조체 템플릿 만드세요
// 2. typedef T type 넣으세요
// 3. 부분전문화를 통한 타입이 분할(?)을 생각하세요.

template<typename T> struct ArrayBaseType
{
	typedef T type;
};

template<typename T, int N> struct ArrayBaseType< T[N] >
{
	typedef T type;
};

template<typename T> void foo(const T& a)
{
	typename ArrayBaseType<int[10]>::type n;  // ArrayBaseType 만드세요
										// 이경우 int가 나와야 합니다.
	cout << typeid(a).name() << endl; //int[10]
	cout << typeid(n).name() << endl; //int
}

int main()
{
	int x[10] = { 0 };

	foo(x);
}