// 3_지연된인스턴스화 - 77 page 3번.
/*
class A
{
	int data;
public:
	void foo(int n) { *n = 10; } // error.
};

int main()
{
	A a;
}
*/

// template code   => C++ 코드생성  => C++코드 컴파일

// 사용되지 않은 함수는 C++ 코드로 생성되지 않음..

template<typename T> class A
{
	T data;
public:
	void foo(T n) { *n = 10; } // error.
};

int main()
{
	A<int> a;
	//a.foo(0);
}
