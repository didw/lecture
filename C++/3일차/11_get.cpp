
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
	cout << (static_cast<xtuple<short, double>&>(t3)).value << endl; 	// 2 ��µǰ� �غ�����.
	cout << (static_cast<xtuple<double>&>(t3)).value << endl;

	int n = xget<1>(t3); // 2�� ���;� �մϴ�.
}

// get �Լ��� ���
template<int N, typename TP> 
TP�� �ִ� N��° ����� Ÿ��& 
xget(TP& tp)    // tp�� tuple�Դϴ�.
{
	return ((N��°�θ�&)tp).value;
}









