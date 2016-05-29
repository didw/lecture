// 3_템플릿기본 - 75 page

//int    square(int a)    { return a * a; }
//double square(double a) { return a * a; }

// 유사한 코드가 반복되면 코드 생성기를 사용하자.

// 1. 매크로를 사용한 코드 생성
//   단점 : 전처리기는 타입을 모른다. 어떤 타입의 함수가 필요한지
//          사용하기 전에 꼭 코드로 표기해야 한다( MAKE_SQUARE(int))
/*
#define MAKE_SQUARE(T) T square(T a) { return a * a;}

MAKE_SQUARE(int)
MAKE_SQUARE(double)
*/

// 2. 컴파일러에 의한 코드 생성 - 컴파일러는 코드를 분석해서 어떤 타입이 필요한지
//							알아 낼수 있다.

// Code Bloat : 템플릿 사용시 컴파일러가 너무 많은 함수(클래스)를 만들어서
//				코드 메모리 사용량이 증가하는 현상

// 인스턴스화 : 템플릿의 타입이 결정되어서 진짜 함수가 되는 과정
// 암시적 인스턴스화 : T를 컴파일러가 결정 
// 명시적 인스턴스화 : T를 사용자가 결정
template<typename T> T square(T a) { return a * a;}

int main()
{
	// 함수 주소 출력
	cout << &square << endl; // error. square는 틀(template)이지 함수가 아니다
	cout << &square<int> << endl; // ok.. 에러 나오면 printf("%p", &square<int>)

	square(3);
	square(3.3);
	short s = 3;
	//square(s); // square(int) 사용 ? square(short)생성 ?

	square<int>(s);
}




