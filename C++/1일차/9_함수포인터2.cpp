// 9_�Լ�������- 22 page �̾߱�
#include <iostream>
using namespace std;

class A { public: int a; void fa() { cout << this << endl; }   };
class B { public: int b; void fb() { cout << this << endl; }   };

class C : public A, public B  // ���� ���
{
public:
	int c;
};

int main()
{
	C ccc;

	cout << &ccc << endl; // 100���� �϶�
	ccc.fa(); // 100
	ccc.fb(); // 104
}


