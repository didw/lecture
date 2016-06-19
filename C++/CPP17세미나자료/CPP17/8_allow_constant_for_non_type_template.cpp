template<int* p> class X {};

struct AAA
{
	int n;
	static int s;
};

int main()
{
	AAA aaa;
	X<&AAA::s> x1; // ok
//	X<&aaa.n> x2;  // error
	X<&aaa.s> x3; //  error until C++14, ok since C++17
}