/*
template<typename T, typename U> struct Duo
{
	T v1;
	U v2;
	static constexpr int N = 2; 
};
//92 page입니다. 어렵습니다.
struct Null {};  // empty class : 아무 멤버도 없는 클래스
				 // 멤버가 없어도 타입입니다.함수 오버로딩이나 템플릿 인자로 활용

template<typename P1 = Null, 
		 typename P2 = Null,
		 typename P3 = Null,
		 typename P4 = Null,
		 typename P5 = Null> 
class tuple : public Duo<P1, tuple<P2, P3, P4, P5, Null>>
{};
// 유효 타입이 2개일때의 tuple을 부분전문화
template<typename P1, typename P2> 
class tuple<P1, P2, Null, Null, Null> : public Duo<P1, P2>
{}

int main()
{
	//										Duo<long, double>
	//							 Duo<short, t<long, double, N,N,N>>
	//                 Duo<char, t<short, long, double, N, N>> 
	// 부모 : Duo<int, t<char, short, long, double, Null>>
	tuple<int, char, short, long, double> t5;

	tuple<int, char, short> t3;
}
*/

#include <tuple> // C++ 표준   
				 // C++98/03 : 10개 까지 보관 
				 // C++11/14 : 이론적으로 무제한(가변인자 템플릿)
using namespace std;

int main()
{
	tuple<int, int, int> t3(1, 2, 3);

	int n = get<1>(t3); // 2
}



