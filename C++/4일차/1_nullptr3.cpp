


void foo(int* p) {}

template<typename F, typename T> void logTime(F f, T a)
{
	f(a);
}
int main()
{
	foo(0); // ok..

	//logTime(foo, 0); // error. 0이 int로 추론되면 int*로 형변환 안됨
	logTime(foo, nullptr); // nullptr_t 는 포인터로 형변환됨.
}






