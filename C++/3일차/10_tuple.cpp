// 10_tuple
#include <iostream>
using namespace std;

template<typename ... Types> class xtuple
{

};

int main()
{
	xtuple<int, int, int> t3;
}

// tuple : ���� �ٸ� Ÿ�� N���� data�� �����ϴ� �����̳�