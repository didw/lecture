// 10_템플릿인자
// 1. type가능.
// 2. 정수형 상수 가능(실수 안됨, 변수 안됨)

template<typename T = int, int N = 10> class stack
{
	T buf[N];
};

int main()
{
	stack<int> s3; // N은 10

	stack<> s4; // 모든 인자를 디폴트로!

	stack<int, 10> s1;

	int a = 10;
	stack<int, a> s2; // error
}


