// 6_함수객체2 - 26 page

// 1. 일반함수는 자신만의 타입이 없다.. Signature가 동일한 함수는 모두 같은 타입이다.

// 2. 함수객체는 자신만의 타입이 있다.. Signature가 동일해도 함수 객체는 모두 다른 타입이다.

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};

struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};



// 정책 변경이 가능하고 정책의 인라인 치환이 가능한 함수
// 템플릿 + 함수 객체로 만드는 기술.
template<typename T> void Sort(int* x, int n, T cmp)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)

			if (cmp(x[i], x[j]))  // 2
				swap(x[i], x[j]);
}

Less    f1; Sort(x, 10, f1);
Greater f2; Sort(x, 10, f2); // ?







