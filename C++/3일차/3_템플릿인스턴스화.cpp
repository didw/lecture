// 3_템플릿인스턴스화

// 아래 코드가 함수 템플릿을 만들고 사용할때 컴파일러에 의한 암시적 추론(deduction)이
// 불가능하게 하는 코드 입니다.

template<typename T> struct identity
{
	typedef T type;
};

//template<typename T> void foo(T a)

template<typename T> void foo( typename identity<T>::type a)
{

}

int main()
{
	//foo(10);    // 컴파일러의 암시적 추론을 막고 싶다.
	foo<int>(10);
}