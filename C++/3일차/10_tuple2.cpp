// 10_tuple
#include <iostream>
using namespace std;

// 핵심 : 첫번째 템플릿 인자는 반드시 독립된 타입이어야 한다.

template<typename T, typename ... Types> class xtuple
{
public:
	T value;

	xtuple() {}

	xtuple(T& a) : value(a) {}

	constexpr int N = 1;
};

int main()
{
	xtuple<int, int, int> t3;
}




// tuple : 서로 다른 타입 N개의 data를 저장하는 컨테이너