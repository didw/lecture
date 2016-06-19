#include <type_traits>
using namespace std;

template<typename F, typename T>
void logTime(F f, T a)
{
	// �����ϸ� ������ ��ȿ���� �����Ͻð��� Ȯ���ϴ°� ����.
	static_assert( is_function<F>::value, "F must be function!!!");

	f(a);
}

int main()
{
	logTime(3, 3); // ?
}
