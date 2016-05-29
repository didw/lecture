/*
template<typename T, typename U> struct Duo
{
	T v1;
	U v2;
	static constexpr int N = 2; 
};
//92 page�Դϴ�. ��ƽ��ϴ�.
struct Null {};  // empty class : �ƹ� ����� ���� Ŭ����
				 // ����� ��� Ÿ���Դϴ�.�Լ� �����ε��̳� ���ø� ���ڷ� Ȱ��

template<typename P1 = Null, 
		 typename P2 = Null,
		 typename P3 = Null,
		 typename P4 = Null,
		 typename P5 = Null> 
class tuple : public Duo<P1, tuple<P2, P3, P4, P5, Null>>
{};
// ��ȿ Ÿ���� 2���϶��� tuple�� �κ�����ȭ
template<typename P1, typename P2> 
class tuple<P1, P2, Null, Null, Null> : public Duo<P1, P2>
{}

int main()
{
	//										Duo<long, double>
	//							 Duo<short, t<long, double, N,N,N>>
	//                 Duo<char, t<short, long, double, N, N>> 
	// �θ� : Duo<int, t<char, short, long, double, Null>>
	tuple<int, char, short, long, double> t5;

	tuple<int, char, short> t3;
}
*/

#include <tuple> // C++ ǥ��   
				 // C++98/03 : 10�� ���� ���� 
				 // C++11/14 : �̷������� ������(�������� ���ø�)
using namespace std;

int main()
{
	tuple<int, int, int> t3(1, 2, 3);

	int n = get<1>(t3); // 2
}



