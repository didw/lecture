
// �ʿ伺 : C++17 Ranges ���̺귯�� ���߽� �ʿ�����..

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

