// 11_Duo - 90 page
#include <iostream>
using namespace std;

template<typename T> void print(const T& a) { cout << T::N << endl; }



template<typename T, typename U> struct Duo
{
	T v1;
	U v2;

	static constexpr int N = 2; // �Ǵ� enum { N = 2}
};

// 2��° ���ڰ� ������϶��� �κ�����ȭ
template<typename A, typename B, typename C> struct Duo<A, Duo<B,C>>
{
	A        v1;
	Duo<B,C> v2;

	static constexpr int N = Duo<B, C>::N + 1;
};

template<typename A, typename B, typename C> struct Duo<Duo<A, B>, C>
{
	Duo<A, B>  v1;
	C          v2;
	static constexpr int N = Duo<A, B>::N + 1;
};

template<typename A, typename B, typename C, typename D> 
struct Duo<Duo<A, B>, Duo<C,D>>
{
	Duo<A, B>  v1;
	Duo<C, D>  v2;
	static constexpr int N = Duo<A, B>::N + Duo<C, D>::N;
};


int main()
{
	Duo<Duo<int, int>, Duo<int, int>> d4;

	print(d4);  // 4������ �غ�����
}

/*
int main()
{
	Duo<Duo<int, int>, int> d3;
	Duo<Duo<Duo<int, int>, int>, int> d4;

	print(d3); // 3������ �غ�����
	print(d4);
}


/*
int main()
{
	Duo<int, int> d2;
	Duo<int, Duo<int, int>> d3;
	Duo<int, Duo<int, Duo<int, int>>> d4;

	print(d2);
	print(d3);
	print(d4);
}
*/





