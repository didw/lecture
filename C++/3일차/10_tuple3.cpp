// 10_tuple
#include <iostream>
using namespace std;

// �ٽ� : ù��° ���ø� ���ڴ� �ݵ�� ������ Ÿ���̾�� �Ѵ�.




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
