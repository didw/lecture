
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

// TP��� tuple�� N��° ���Ÿ���� ���ϴ� Traits..
template<int N, typename TP> struct xtuple_element;

/*
{
	typedef void type;
};
*/
// N�� 0�϶��� ���� �κ� ����ȭ
/*
template<typename TP> struct xtuple_element<0, TP>
{
	typedef ? type;
};
*/
// ���� ó�� �ϸ� tuple<int, short, double> ��ü��  TP�� ���εǹǷ�
// int�� ���Ҽ� ����.!!

// �Ʒ� �ڵ尡 �ٽ��Դϴ�.
template<typename T, typename ... Types> 
struct xtuple_element<0,  xtuple<T, Types...> >
{
	typedef T type;							// 0��° ��� Ÿ��
	typedef xtuple<T, Types...>  tupleType; // 0��° ��Ҹ� �����ϴ� tupleŸ��
};

// 0�� �ƴ� N��° ���ϱ�
template<int N, typename T, typename ... Types>
struct xtuple_element<N, xtuple<T, Types...> >
{
	typedef typename xtuple_element<N-1, xtuple<Types...>>::type type;
	typedef typename xtuple_element<N-1, xtuple<Types...>>::tupleType tupleType;
};


template<typename TP> void foo(TP& tp)
{
	cout << "Ʃ�� Ÿ�� : " << typeid(TP).name() << endl;

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








