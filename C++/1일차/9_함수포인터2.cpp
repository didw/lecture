// 9_함수포인터- 22 page 이야기
#include <iostream>
using namespace std;

class A { public: int a; void fa() { cout << this << endl; }   };
class B { public: int b; void fb() { cout << this << endl; }   };

class C : public A, public B  // 다중 상속
{
public:
	int c;
};

int main()
{
	C ccc;

	cout << &ccc << endl; // 100번지 일때
	ccc.fa(); // 100
	ccc.fb(); // 104
}


