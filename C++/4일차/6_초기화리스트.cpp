// 6_�ʱ�ȭ����Ʈ - 208 page
#include <iostream>
using namespace std;

int main()
{
	// C++11 ǥ���� �����ϴ� Ÿ��
	// tuple : ���� �ٸ� Ÿ���� data ����
	// initializer_list : ���� Ÿ���� data ����
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