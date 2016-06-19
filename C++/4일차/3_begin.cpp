// 3_begin - 195 page
#include <iostream>
#include <list>
#include <type_traits>
using namespace std;

// ��� �����̳��� ��Ҹ� �����ϴ� �Լ�
template<typename T> void show(T& s)
{
	// �ݺ��� : �����Ϳ� ������ ��ü.
	typename T::iterator p = s.begin(); 
	while (p != s.end())
	{
		cout << *p << endl;
		++p;
	}
}
int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 }; // C++11 ���� �̷��� �ʱ�ȭ ����
	show(s);

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	show(x);  //?
}





