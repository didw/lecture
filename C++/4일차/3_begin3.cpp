// 3_begin - 195 page
#include <iostream>
#include <list>
#include <type_traits>
using namespace std;


/*
// ����� �ƴ� begin/end  �Լ�
template<typename T> auto begin(T& c) { return c.begin(); }
template<typename T> auto end(T& c)   { return c.end(); }

template<typename T, int N> auto begin( T(&c)[N]) { return c; }
template<typename T, int N> auto end(   T(&c)[N]) { return c + N; }
*/



// C++98���� : STL ���� s.begin()���� �ݺ��ڸ� ���½��ϴ�
// C++11���� : begin(s) �� ����Ͻô°��� �����ϴ�. (�迭�� ����ؼ�)
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
	// C++11 ranged for ���
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





