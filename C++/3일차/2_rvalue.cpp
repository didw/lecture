// 2_rvalue

int x = 10;
int  foo() { return x; }
int& goo() { return x; }

// lvalue : 등호의 왼쪽과 오른쪽에 모두 올수 있다.
// rvalue : 등호의 오른쪽에만 올수 있다.


int main()
{
	int v1 = 10, v2 = 20;

	v1 = 10;

	v2 = v1;
	10 = v2; // error

	foo() = 10; // error
	goo() = 10; // ok..

	int* p1 = &v1;
	int* p2 = &10;

	const int c = 10;
	c = 20; // 수정불가능한 lvalue (이름이 있고, 메모리에 계속 존재, 주소도 구할수있다.)
}


