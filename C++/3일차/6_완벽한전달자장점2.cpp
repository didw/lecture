
#include <iostream>
using namespace std;

// C++11은 멀티스레드를 지원합니다.
#include <thread>

void foo(int a, int b, double d)
{
	cout << "foo" << endl;
}
int main()
{
	thread t(foo, 10, 20, 3.4); // 이순간 스레드가 생성됩니다.

	t.join();
}





