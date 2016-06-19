// 4_range_for
#include <iostream>
#include <list>
#include <type_traits>
using namespace std;

int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	for (int n : s)
		cout << n << endl;


	// 위 코드를 보고 컴파일러는 아래 코드를 생성합니다.
	for (auto p = begin(s); p != end(s); ++p)
	{
		int n = *p;

		cout << n << endl;
	}
}





