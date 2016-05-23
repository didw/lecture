// 5_인라인함수3
#include <algorithm>
using namespace std;

// 라이브러리 설계자를 생각해 봅시다.
// 1. 성능. 빨라야 한다.
// 2. 유연성. 정책 변경이 가능해야 한다.

// 공통성과 가변성의 규칙
// 변하지 않은 전체적인 알고리즘에서 변해야 하는 부분(정책)이 있다면 
// 분리해 내야 한다.

// 일반 함수의 경우 : 변하는 것을 함수 인자로 뽑아낸다(함수 포인터)



void Sort(int* x, int n, bool(*cmp)(int,  int) ) // C언어의 qsort()원리
{
	for (int i = 0; i < n - 1; i++)

		for (int j = i + 1; j < n; j++)

//			if ( x[i] > x[j] )     // 1

			if( cmp(x[i], x[j]) )  // 2
				swap( x[i], x[j] );
}
//----------------------------------------
// 비교 정책을 담은 함수들 

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }




int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	
	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}
// 25page 입니다.



