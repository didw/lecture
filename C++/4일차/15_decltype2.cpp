// 15_decltype2

int main()
{
	int n = 10;
	int* p = &n;

	int x[4] = { 1,2,3,4 };
	
	// 각 타입 추론해보세요
	// foo() = 값, 즉 함수 호출이 lvalue가 되려면 참조 리턴이 필요 하다.
	// 연산의 결과가 좌변에 올수 있는지를 생각해라.!
	decltype(n)    d1; // int
	decltype(p)    d2; // int*
	decltype(*p)   d3 = n; // int&
	d3 = 100;
	decltype(x[0]) d4; // int&

	decltype(++n)  d5; // int&   // ++n = 3 .. ok.. 가능하다. ++(++n)
	decltype(n++)  d6; // int
	decltype(n+n)  d7; // n + n = 3; 처럼 좌변에 올수 없다. 
					   // int로 추론 
}




