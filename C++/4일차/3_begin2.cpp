// 3_begin - 195 page
#include <iostream>
#include <list>
#include <type_traits>
using namespace std;

// 모든 컨테이너의 요소를 열거하는 함수
template<typename T> void show_imp(T& s, false_type )
{
	// 반복자 : 포인터와 유사한 객체.
	typename T::iterator p = s.begin();
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}
// 배열 버전.
template<typename T> void show_imp(T& s, true_type)
{
	auto p = s;
	while (p != s + extent<T,0>::value )
	{
		cout << *p << endl;
		++p;
	}
}


template<typename T> void show(T& s)
{
	// 배열여부에 따라서 함수 오버로딩 사용
	show_imp(s, is_array<T>() );
}


int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 }; 
	show(s);

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	show(x);  //?
}





