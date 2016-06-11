
// rvalue와 참조..
int main()
{
	int v1 = 10;

	// 1. 일반 참조 : lvalue 만 참조 할수 있다.
	int& r1 = v1; // ok
	int& r2 = 10; // error

	// 2. const 참조 : lvalue와 rvalue 모두 참조 가능
	//					단, 원본에 const 속성을 추가해서 접근하게 된다.
	const int& r3 = v1; // ok..
	const int& r4 = 10; // ok..

	// 3. C++ 11 의 rvalue reference  : rvalue 만 참조 할수 있다.
	//        "perfect forwarding"과 move semantics 때문에 만든 문법

	int&& r5 = v1; // error
	int&& r6 = 10; // ok

}




