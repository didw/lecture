// 15_constexpr_lambda

// ¶÷´Ù¿Í constexpr

template<int N> class Test {};


int main()
{
	constexpr auto add = [](int a, int b) { return a + b; };

	Test<add(1, 2)> t1;

	int n1 = 1, n2 = 2;

	int n = add(n1, n2);

	auto add2 = [](int a, int b) constexpr { return a + b; };
	
	Test<add2(1, 2)> t2;


	auto add3 = [](int a, int b) { return a + b; };
	
	constexpr int c = add3(1, 2);
	constexpr int(*f)(int, int) = add3;
	
	Test<add3(1, 2)> t3;


}