#include <iostream>
using namespace std;

/*
// 과제 : 함수의 인자가 3개라고 가정하고.. 1번째 인자의 타입을 얻어내는
//        메타 함수를 만들어 보세요

FirstArgumentType<T>::type n;

// 도전 과제 - 인자가 3개라고 가정
ArgumentType<T, 2>::type n;


// 최종 도전 : 인자의 갯수가 0~N 개일때.. 다음주에 배웁니다.
*/


// 인자가 1개인 함수만 생각합니다.

int f1(double d) { return 0; }


template<typename T> struct ResultType
{
	typedef T type;
};

template<typename R, typename A> struct ResultType<R(A)>
{
	typedef R type;
};

template<typename T> void foo(const T& a)  // 참고 함수 타입 : int(double) 
{
	typename ResultType<T>::type n;

	cout << typeid(n).name() << endl;
}
int main()
{
	foo(f1);
}
