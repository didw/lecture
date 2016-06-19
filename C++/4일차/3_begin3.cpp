// 3_begin - 195 page
#include <iostream>
#include <list>
#include <type_traits>
using namespace std;


/*
// 멤버가 아닌 begin/end  함수
template<typename T> auto begin(T& c) { return c.begin(); }
template<typename T> auto end(T& c)   { return c.end(); }

template<typename T, int N> auto begin( T(&c)[N]) { return c; }
template<typename T, int N> auto end(   T(&c)[N]) { return c + N; }
*/



// C++98까지 : STL 사용시 s.begin()으로 반복자를 꺼냈습니다
// C++11부터 : begin(s) 로 사용하시는것이 좋습니다. (배열도 고려해서)
/*
template<typename T> void show(T& s)
{
	auto p = begin(s); //s.begin();

	while (p != end(s))   // s.end())
	{
		cout << *p << endl;
		++p;
	}
}
*/
template<typename T> void show(T& s)
{
	// C++11 ranged for 사용
	for (auto n : s)
		cout << n << endl;
}

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 }; 
	show(s);

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	show(x);  //?
}





