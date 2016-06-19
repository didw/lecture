// 2_static_assert- 186 page

#include <iostream>
#include <cassert>   // assert()를 위해
using namespace std;


// C++11 컴파일 시간 assert 제공
static_assert(sizeof(double) > 8, "error. double이 8바이트이상일때만 컴파일됨");


void foo(int age)
{
	// 인자를 사용하기 전에 인자값의 유효성을 확인하는 것이 좋다.
	assert(age > 0);
	
	int* p = new int[age]; 
}
int main()
{
	foo(-10);
}




