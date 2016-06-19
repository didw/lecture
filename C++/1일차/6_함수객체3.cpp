// 6_함수객체3
#include <iostream>
#include <algorithm> // 이안에 이미 sort()가 있습니다.
using namespace std;

// 인라인함수 3에서 cmp1, cmp2, 복사해오세요
// Less, Greater 복사 해오세요

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// sort의 3번째 인자는 템플릿 입니다

	// 1. 정책으로 일반함수를 사용할때
	
	// 장점 : 정책을 교체해도 sort() 기계어 코드는 한개 이다. 메모리 사용량증가안함
	// 단점 : 정책 함수가 인라인 치환 될수 없다. 느리다.

	sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int, int)) 인 함수생성
	sort(x, x + 10, cmp2); // sort(int*, int*, bool(*)(int, int)) 인 함수생성

	// 2. 정책으로 함수객체를 사용할때

	// 단점 : 정책을 교체하면 sort() 기계어 코드는 여러개 이다. 메모리 사용량증가
	// 장점 : 정책 함수가 인라인 치환 될수 있다.

	Less    f1;
	Greater f2;
	sort(x, x + 10, f1); // sort( int*, int*, Less) 인 함수 생성
	sort(x, x + 10, f2); // sort( int*, int*, Greater) 인 함수 생성
}

// 28 page ...


