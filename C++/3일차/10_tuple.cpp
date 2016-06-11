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

// tuple : 서로 다른 타입 N개의 data를 저장하는 컨테이너