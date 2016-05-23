


// cl 5_인라인함수.cpp   /FAs  /Ob1    => 24 page 제일 위에 있습니다.

// 5_인라인함수 - 24 page

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2);
	int n2 = Add2(1, 2);
}