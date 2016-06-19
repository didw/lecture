//1_nullptr2

#include <iostream>
using namespace std;
// C++11 : 포인터 0을 만들었습니다

int main()
{
	int* p = nullptr; // ok
	//int  n = nullptr; // error

	// nullptr 은 nullptr_t 타입입니다.
	// 모든 타입의 포인터로 암시적 형변환 됩니다.
	nullptr_t a = nullptr;
}