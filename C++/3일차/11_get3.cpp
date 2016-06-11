
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

// TP라는 tuple의 N번째 요소타입을 구하는 Traits..
template<int N, typename TP> struct xtuple_element;


template<typename T, typename ... Types>
struct xtuple_element<0, xtuple<T, Types...> >
{
	typedef T type;							
	typedef xtuple<T, Types...>  tupleType; 
};

// 0이 아닌 N번째 구하기
template<int N, typename T, typename ... Types>
struct xtuple_element<N, xtuple<T, Types...> >
{
	typedef typename xtuple_element<N - 1, xtuple<Types...>>::type type;
	typedef typename xtuple_element<N - 1, xtuple<Types...>>::tupleType tupleType;
};

template<int N, typename TP>
typename xtuple_element<N, TP>::type&
xget(TP& tp)    
{
	return (static_cast<typename xtuple_element<N, TP>::tupleType&>(tp)).value;
}
int main()
{
	xtuple<int, short, double> t3(1, 2, 3.4);

	cout << xget<2>(t3) << endl;
	xget<0>(t3) = 10;
	cout << xget<0>(t3) << endl;
}








