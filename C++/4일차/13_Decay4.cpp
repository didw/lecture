
// 배열을 템플릿으로 보낼때
// 값(T)   : 포인터로 추론되어서 받게 된다.
// 참조(T&): 정확한 배열로 추론되어서 받게 된다.

template<typename T> void foo(T a, T b)
{
}

template<typename T> void goo(T& a, T& b)
{
}

int main()
{
	foo("apple", "banana");
	goo("apple", "banana"); // error. 왜 ?
}