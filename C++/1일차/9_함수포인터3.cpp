// 9_함수포인터- 22 page 이야기
#include <iostream>
using namespace std;

class A { public: int a; void fa() { cout << this << endl; } };
class B { public: int b; void fb() { cout << this << endl; } };

class C : public A, public B  // 다중 상속
{
public:
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl; // 100번지 일때


	void(C::*f)(); // 멤버 함수 포인터
				   // f 정체는 구조체 입니다. { 함수주소, this_offset }

	cout << sizeof(f) << endl;

	f = &C::fa; // { fa주소, 0}
	//f = &C::fb;// { fb주소, sizeof(A) }
	
	(ccc.*f)(); // 결과 생각해보세요
				// f(&ccc + sizeof(A) )

				// f.함수주소( &ccc + f.this_offset)
}

// 연구 과제..
class Shape
{
public:
	virtual void Draw() = 0;
};

void(Shape::*f)() = &Shape::Draw; // ???



