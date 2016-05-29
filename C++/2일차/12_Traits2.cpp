// 12_traits
#include <iostream>
using namespace std;

// Traits : 템플릿 인자T에 대한 다양한 정보를 얻는 도구.
//          컴파일 시간에 사용되는 함수 => 메타 함수라고 합니다.

// 만드는 법
// 1. 구조체 템플릿으로 만듭니다.
// 2. primary template 버전에서 false 리턴 ( value = false라는 의미)
// 3. 부분 전문화 버전           true 리턴 ( value = true 라는 의미)

/*
struct People
{
	int age = 0;
	bool value = false; // error.
	enum { value = false }; // ok..
	static const bool value = false; // 2000년 후반에 이문법 허용.
}
*/

template<typename T> struct IsPointer
{
	//enum { value = false }; // 예전 스타일
	static constexpr bool value = false; // C++11 스타일
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};


template<typename T> void foo(const T& a)
{	
	if ( IsPointer<T>::value )  cout << "포인터 입니다." << endl;
	else                 	  cout << "포인터가 아닙니다" << endl;
}

int main()
{
	int n = 0;
	foo(&n);
}





