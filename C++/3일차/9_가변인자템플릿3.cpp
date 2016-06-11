#include <iostream>
using namespace std;

// 가변인자 꺼내서 사용하기 - 중요!!

// 핵심 1. 1번째 인자는 반드시 독립된 일반 변수에 받아야 한다.
//      2. 재귀 호출과 유사한 모양으로 나머지 인자를 꺼내게  된다.
//         재귀 호출은 아니다.


template<typename T, typename ... Types> 
void foo(T value, Types ... args)
{
	static int n = 0;
	++n;

	cout << n << " : " << typeid(T).name() << " : " << value << endl;

	foo(args...);   // foo(3.4, 4)  value : 3.4  args : 4
					// foo(4)       value : 4    args : 
					// foo()
}

void foo() {}

int main()
{
	foo(1, 3.4, 4); // value : 1    args : 3.4  4
}









