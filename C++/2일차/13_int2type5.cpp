#include <iostream>
using namespace std;


// 99 page
/*
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};

integral_constant<int,   0> n0;
integral_constant<short, 0> s0;


// true/false             : 참 거짓을 나타내는 값, 같은 타입
// true_type / false_type : 참 거짓을 나타내는 타입, 다른 타입
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// is_pointer 만들기
// 결국 부모인 false_type안에 value = false가 있습니다.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};

*/

#include <type_traits> // 이 안에 위에 있는 코드가 있습니다.

template<typename T> void printv_imp(T a, true_type )  { cout << a << " : " << *a << endl;}
template<typename T> void printv_imp(T a, false_type ) { cout << a << endl;}


template<typename T> void printv(T a)
{

	printv_imp(a, is_pointer<T>() );  // 클래스이름() :임시객체 생성
									 //  Point(); // Point 객체 생성
}







int main()
{
	int n = 10;

	printv(n);

}


