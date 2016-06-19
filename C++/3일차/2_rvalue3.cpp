#include <iostream>
using namespace std;

// 참조와 함수 오버로딩 - 48 page

void foo(int& a)       { cout << "int&" << endl; }
void foo(const int& a) { cout << "const int&" << endl; }
void foo(int&&)        { cout << "int&&" << endl; }

int main()
{
	int v1 = 10;

//	foo(v1); // int& 없으면 const int& 
//	foo(10); // int&& 없으면 const int&&

	int& r1 = v1;
//	foo(r1); // 1

	int&& r2 = 10;  // 10은 rvalue 이지만
					// 10을 가르키는 rvalue reference 형 변수 자체는 lvalue이다.
					// "이름이 있는 rvalue reference 형 변수는 lvalue이다."
					
					// rvalue와 rvalue reference를 나누에 생각하세요.

	foo(r2); // r2는 lvalue 이므로 int&

	foo(static_cast<int&&>(r2)); // int&& 
								// 이 캐스팅은 r2를 _rvalue_로 캐스팅하는 코드 입니다
}





