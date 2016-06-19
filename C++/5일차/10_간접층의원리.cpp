// 10_간접층의원리

// 아무리 어려운 문제도 간접층(대행자)를 만들면 해결할수 있다.

// Vector의 크기로 int 대신 대행자를 사용하자
struct VectorSize
{
	int size;
	VectorSize(int n) : size(n) {} // int => VectorSize 암시적 형변환 가능.
};

class Vector
{
public:
	Vector(VectorSize vs) // VectorSize => Vector 암시적 형변환 가능.
	{
		int n = vs.size;
	}
//	Vector(int n) {}
};

void foo(Vector v) {}

int main()
{
	Vector v(10); //ok..
	foo(v); // ok
	foo(10); // 10(int) => Vector 로 암시적 형변환
}



