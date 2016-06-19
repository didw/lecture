#include <iostream>
#include <boost/coroutine/coroutine.hpp>

typedef boost::coroutines::coroutine<int()> generator;

void bar(generator::caller_type& yield)
{
	for (std::size_t i = 100; i < 110; ++i)
		yield(i);
}

void foo(generator::caller_type& yield)
{
	for (std::size_t i = 0; i < 10; ++i)
	{
		generator nested_gen(bar);
		while (nested_gen)
		{
			std::cout << "foo: " << nested_gen.get() << std::endl;
			nested_gen();
		}
		yield(i);
	}
}

int main()
{
	generator gen(foo);
	while (gen)
	{
		std::cout << "main: " << gen.get() << std::endl;
		gen();
	}
	return 0;
};