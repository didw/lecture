#include <type_traits>
using namespace std;

template<typename F, typename T>
void logTime(F f, T a)
{
	// 가능하면 인자의 유효성을 컴파일시간에 확인하는게 좋다.
	static_assert( is_function<F>::value, "F must be function!!!");

	f(a);
}

int main()
{
	logTime(3, 3); // ?
}
