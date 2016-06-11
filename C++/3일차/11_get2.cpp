
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

/*
{
	typedef void type;
};
*/
// N이 0일때를 위한 부분 전문화
/*
template<typename TP> struct xtuple_element<0, TP>
{
	typedef ? type;
};
*/
// 위에 처럼 하면 tuple<int, short, double> 전체가  TP에 매핑되므로
// int를 구할수 없다.!!

// 아래 코드가 핵심입니다.
template<typename T, typename ... Types> 
struct xtuple_element<0,  xtuple<T, Types...> >
{
	typedef T type;							// 0번째 요소 타입
	typedef xtuple<T, Types...>  tupleType; // 0번째 요소를 저장하는 tuple타입
};

// 0이 아닌 N번째 구하기
template<int N, typename T, typename ... Types>
struct xtuple_element<N, xtuple<T, Types...> >
{
	typedef typename xtuple_element<N-1, xtuple<Types...>>::type type;
	typedef typename xtuple_element<N-1, xtuple<Types...>>::tupleType tupleType;
};


template<typename TP> void foo(TP& tp)
{
	cout << "튜플 타입 : " << typeid(TP).name() << endl;

	typename xtuple_element<2, TP>::type n;  // double

	cout << typeid(n).name() << endl;


	typename xtuple_element<2, TP>::tupleType t;
	cout << typeid(t).name() << endl;   // xtuple<double>
}


int main()
{
	xtuple<int, short, double> t3(1, 2, 3.4);

	foo(t3);
}








