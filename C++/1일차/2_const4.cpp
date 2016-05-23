// 3_const4

// C++11의 constexpr 함수 : 함수 인자로 literal 이 전달되면
//						컴파일 시간에 함수의 연산을 수행해 준다.
constexpr int Add(int a, int b)
{
	return a + b;
}

int main()
{
	int x[ Add(1, 2) ]; // ??
	
	int a = 1, b = 2;
	Add(a, b);
}


