// 13_Decay
#include <iostream>
using namespace std;

int main()
{
	int n = 10; // n은 int 타입

	int *p = &n; // p 는 int* 타입.
				 // 규칙 1. 선언문에서 변수이름을 제거하면 타입이 남는다.
				 // 규칙 2. 변수의 주소를 꺼내려면 변수 이름 앞에 &를 붙인다.
				 // 규칙 3. 포인터 변수를 만들려면 
				 //         변수 선언식에서 변수이름 앞에 *를 붙인다.

	int x[5]; // x의 타입 => int[5]


	int y[10] = { 0 };

	// y의 주소를 담는 포인터 변수 py를 만드세요.. y 주소로 초기화 하세요..
	int (*py)[10] = &y; // 배열의 주소

	int* py2 = y; // 배열의 이름은 배열의 첫번째 요소의 주소로 암시적 형변환됩니다.
				  // "array to pointer conversion" 이라는 문법. 
				  // 흔히 "decay"라고도 합니다.

	cout << py  << ", " << py  + 1 << endl;
	cout << py2 << ", " << py2 + 1 << endl;

	
	int ar[3][2] = { { 1,2}, {3,4}, {5,6} };

	int (*p1)[3][2] = &ar;

	int (*p2)[2] = ar;

}






