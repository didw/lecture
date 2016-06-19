
// 필요성 : C++17 Ranges 라이브러리 개발시 필요했음..

{
	auto && __range = for - range - initializer;

	for (auto __begin = begin - expr, __end = end - expr; __begin != __end; 	++__begin) 
	{
		for - range - declaration = *__begin;
		statement
	}
}
{
	auto && __range = for - range - initializer;
	
	auto __begin = begin - expr;
	auto __end = end - expr;

	for (; __begin != __end; ++__begin) 
	{
		for - range - declaration = *__begin;
		statement
	}
}

