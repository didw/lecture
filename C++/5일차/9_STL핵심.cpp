// 9_STL핵심
#include <vector>
#include <list>
#include <string>
#include <algorithm>  // find()같은 일반함수를 "알고리즘"이라고 합니다.
#include <iostream>
using namespace std;

int main()
{
	vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// v를 sort()해 보세요
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (auto n : v)
		cout << n << endl;


	list<int> s = { 1,3,5,7,9,2,4,6,8,10 };

	// 정렬해 보세요
	sort(s.begin(), s.end()); // ??

	for (auto n : s)
		cout << n << endl;

}













