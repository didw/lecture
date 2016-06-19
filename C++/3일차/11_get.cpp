
#include <iostream>
using namespace std;


template<typename T, typename ... Types>
class xtuple : public xtuple<Types...>   
{
	typedef xtuple<Types...> Base;
public:
	T value;
	xtuple() {}
	xtuple(const T& a, const Types& ... args) : value(a), Base(args...) {}
	static constexpr int N = 1 + Base::N;
};
template<typename T> class xtuple<T>
{
public:
	T value;
	xtuple() {}
	xtuple(const T& a) : value(a) {}
	static constexpr int N = 1;
};
//-------------------------------------------------------


int main()
{
	xtuple<int, short, double> t3(1, 2, 3.4);

	cout << t3.value << endl;  // 1
	cout << (static_cast<xtuple<short, double>&>(t3)).value << endl; 	// 2 출력되게 해보세요.
	cout << (static_cast<xtuple<double>&>(t3)).value << endl;

	int n = xget<1>(t3); // 2가 나와야 합니다.
}

// get 함수의 모양
template<int N, typename TP> 
TP에 있는 N번째 요소의 타입& 
xget(TP& tp)    // tp가 tuple입니다.
{
	return ((N번째부모&)tp).value;
}









