// 7_람다12

int main()
{
	int(*f)(int, int);

	{
		int v1 = 10;

		f = [&v1](int, int) { return v1; }; // error 의 원인은 2주차에 자세히 설명드립니다.
	}

	f(1,2); // 문제점을 잘 생각해 보세요.
	/*
	int* p = new int[10];
	delete[] p; // 미정의 동작(Undefined) 발생.
				// p는 int* 이다.

	int* p1 = new int;
	delete p1; // p1은 int*라는 사실을 안다. 4바이트 해지
	*/
}