// 10_tuple
#include <iostream>
using namespace std;

// �ٽ� : ù��° ���ø� ���ڴ� �ݵ�� ������ Ÿ���̾�� �Ѵ�.

template<typename T, typename ... Types> class xtuple
{
public:
	T value;

	xtuple() {}

	xtuple(T& a) : value(a) {}

	constexpr int N = 1;
};

int main()
{
	xtuple<int, int, int> t3;
}




// tuple : ���� �ٸ� Ÿ�� N���� data�� �����ϴ� �����̳�