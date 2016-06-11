// 6_초기화리스트 - 208 page
#include <iostream>
using namespace std;

int main()
{
	// C++11 표준이 제공하는 타입
	// tuple : 서로 다른 타입의 data 보관
	// initializer_list : 동일 타입의 data 보관
	initializer_list<int> e = { 1,2,3,4 };

	//initializer_list<int>::iterator p = e.begin(); // C++ 98 style

	auto p = begin(e); // C++11

	while (p != e.end())
	{
		cout << *p << endl;
		++p;
	}

	for (auto n : e)
		cout << n << endl;

}