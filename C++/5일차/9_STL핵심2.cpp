#include <vector>
#include <list>
#include <string>
#include <algorithm>  
#include <iostream>
using namespace std;

// 반복자의 6가지 분류.. - 181 page

// 1. 입력 반복자 : =*p, ++
// 2. 출력 반복자 : *p=, ++
// 3. 정방향 반복자 : 입출력, ++,     싱글리스트
// 4. 양방향 반복자 : 입출력, ++, --  더블리스트
// 5. 임의 접근 반복자 : 입출력, ++, --, +, -, []  => 연속된 메모리 또는
//													연속된 메모리와 유사

// 6. continusly iterator(C++11/14에서 추가) : 연속된 메모리의 반복자
//										임의접근과 거의 유사

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* p = find(x, x + 10, 5); // 1,2 번째 인자는 반복자 입니다. 최소 조건은 ?
								// 입력 반복자

	reverse(x, x + 10); // 최소 조건 ? 양방향 반복자

	sort(x, x + 10); // 퀵 소트 알고리즘입니다. 임의 접근 반복자

	//-------------------------------------
//	slist<int> s = { 1,2,3 };
//	reverse(s.begin(), s.end()); // ?


	list<int> ss = { 1,2,3 };
	//sort(ss.begin(), ss.end()); // ?
	ss.sort(); // 퀵 대신 다른 알고리즘.


	vector<int> v = { 1,2,3 };

	v.sort(); // 이 멤버 함수가 있을까요 ?

	sort()
}








/*
int main()
{
	slist<int> s = { 1,2,3 }; // 우리가 만든 싱글리스트를 생각해봅시다

	slist<int>::iterator p = s.begin();

	++p; // ok
	--p; // ?? 될까요 ?? 문법적으로 는 가능하지만 자료 구조 특성상 안된다.
}
*/