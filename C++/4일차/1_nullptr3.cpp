


void foo(int* p) {}

template<typename F, typename T> void logTime(F f, T a)
{
	f(a);
}
int main()
{
	foo(0); // ok..

	//logTime(foo, 0); // error. 0�� int�� �߷еǸ� int*�� ����ȯ �ȵ�
	logTime(foo, nullptr); // nullptr_t �� �����ͷ� ����ȯ��.
}






