
#include <iostream>
using namespace std;

// C++11�� ��Ƽ�����带 �����մϴ�.
#include <thread>

void foo(int a, int b, double d)
{
	cout << "foo" << endl;
}
int main()
{
	thread t(foo, 10, 20, 3.4); // �̼��� �����尡 �����˴ϴ�.

	t.join();
}





