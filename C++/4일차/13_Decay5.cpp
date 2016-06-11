#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;

typedef void FUNC(int);  // FUNC는 함수 타입
typedef void(*PFUNC)(int); // 함수 포인터 타입

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo; // 정확한 표현
	void(*f2)(int) = foo; // 함수의 이름의 함수 코드 첫번째 주소로 암시적 형변환

	PFUNC f3 = &foo;
	FUNC* f4 = &foo;
	FUNC* f5 = foo;

	FUNC f6 = foo; // error. 함수도 배열처럼 복사 생성될수 없다.

	FUNC& r = foo; // ok
}









