#include <iostream>
using namespace std;

// 교재 2 page
int main()
{
	cout << "hello" << endl;

	int n1 = 0b101;
	
	cout << n1 << endl;

	int n2 = 1'000'000;

	auto n3 = n2; // 우변의 타입 조사해서 좌변의 타입으로 결정해 달라

	decltype(n3) n4; // n3와 동일타입변수 n4

	int x[10] = { 1,2,3 };

	//decltype(x[0]) n5; // n5 ? int&
	int& r = n1;
	auto a2 = r; // a2는 int& 가 아니라  int 이다.


	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}

	for (int a : x)
		cout << a << endl;
}

// trailing return 또는 suffix return type 이라고 부르는 문법.
auto foo() -> int
{
	return 0;
}

// 빌드 하는 법 : Ctrl + Shift + B
// 빌드 + 실행 : Ctrl + F5