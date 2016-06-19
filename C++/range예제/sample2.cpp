#include <iostream>
#include <vector>           
#include <range/v3/all.hpp> 
using namespace std;
using namespace ranges;

int main()
{
	vector<int> v1{1,2,3,4,5,6,7,8,9,10};

	auto r1 = v1 | view::take(9) | view::filter([](int a) { return a % 2 == 0; });

	cout << r1 << endl;

	vector<int> v2{1,1,1,2,2,2,3,3,4};

	// 조건을 만족하는 근접한 요소끼리의 그룹을 만듭니다.
	// 리턴값은 결국 range의 range 입니다.
	auto r2 = v2 | view::group_by([](int a, int b) { return a == b; });

	cout << r2 << endl;

	RANGES_FOR(auto r3, r2)
		cout << r3 << endl;
}


