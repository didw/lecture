// 2_const
#include <iostream>
using namespace std;
// 9 page
int main()
{
//	const int c = 10; // 컴파일 시간 상수

	int n = 10;
	const int c = n; // runtime 상수

	int* p = const_cast<int*>(&c); // 상수성을 제거하는 캐스팅
							// C스타일 캐스팅도 가능...(int*)&c

	*p = 20;

	cout << c  << endl; // 10   20
	cout << *p << endl; // 20   20
}