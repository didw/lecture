// 5_클래스템플릿 - 79 page

template<typename T> class stack
{
	T buf[10];
public:
	// 다음중 생성자로 맞는 것은 ?
	stack()    {} // 1 ok..
	stack<T>() {} // 2 일부 컴파일러는 허용.. 하지만 1처럼 사용해야 한다.

	// 복사 생성자로 맞는 것은 ?
	stack(const stack&    s) {} // 1. 복사 생성자 일경우만 이표현 허용.
	stack(const stack<T>& s) {} // 2. ok..

	// 멤버 함수의 외부 구현
	void push(T a);

	// 클래스 템플릿의 멤버 함수 템플릿
	template<typename U> T foo(U a);
};


template<typename T> template<typename U> T stack<T>::foo(U a)
{

}





template<typename T> void stack<T>::push(T a) // 80 page 제일 윗부분
{

}


//template<typename T> void foo(stack& s)    {} // 1. error
//template<typename T> void foo(stack<T>& s) {} // 2. ok

int main()
{
	stack      s1; // error. stack 은 타입이 아니다. 틀(template)이다.
	stack<int> s2; // ok.    stack<int> 는 타입이다.
}






