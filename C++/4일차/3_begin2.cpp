// 3_begin - 195 page
#include <iostream>
#include <list>
#include <type_traits>
using namespace std;

// ��� �����̳��� ��Ҹ� �����ϴ� �Լ�
template<typename T> void show_imp(T& s, false_type )
{
	// �ݺ��� : �����Ϳ� ������ ��ü.
	typename T::iterator p = s.begin();
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}
// �迭 ����.
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
	// �迭���ο� ���� �Լ� �����ε� ���
	show_imp(s, is_array<T>() );
}


int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 }; 
	show(s);

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	show(x);  //?
}





