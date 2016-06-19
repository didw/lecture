// 6_STL알고리즘
#include <iostream>
using namespace std;



// Step 5. 실패의 전달 : 0 대신 last 리턴.

// 모든 타입의 배열 [first, last) 구간에서 선형 검색 수행.
// last 는 검색 대상이 아님.

template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first;// == last ? 0 : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = xfind(x, x + 10, 5);

	if (p == x + 10 )
		cout << "찾을수 없습니다." << endl;
	else
		cout << *p << endl;
}

