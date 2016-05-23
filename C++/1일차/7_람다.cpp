// 7_람다
#include <iostream>
#include <functional> // 이안에 이미 less, greater가  있습니다.
using namespace std;

int main()
{
	int x[10] = { 1,2,3 };

	sort(x, x + 10, cmp1);

	less<int> f1;
	sort(x, x + 10, f1);

	// C++11 : Lambda Expression(람다 표현식)

	// [] : 람다가 시작됨을 알리는 표시
	//      "Lambda Introducer"
	sort(x, x + 10, [](int a, int b) { return a < b;} );
}




