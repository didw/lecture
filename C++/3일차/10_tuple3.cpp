// 10_tuple
#include <iostream>
using namespace std;

// 핵심 : 첫번째 템플릿 인자는 반드시 독립된 타입이어야 한다.




template<typename T, typename ... Types> 
class xtuple : public xtuple<Types...>   // xtuple<short, double>
{
	typedef xtuple<Types...> Base;
public:
	T value;

	xtuple() {}
	xtuple(const T& a, const Types& ... args ) : value(a), Base(args...) {}

	constexpr int N = 1 + Base::N;
};

int main()
{
	xtuple<int, short, double> t3(1, 2, 3.4); // T : int   Types : short double
}
