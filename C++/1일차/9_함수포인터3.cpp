// 9_�Լ�������- 22 page �̾߱�
#include <iostream>
using namespace std;

class A { public: int a; void fa() { cout << this << endl; } };
class B { public: int b; void fb() { cout << this << endl; } };

class C : public A, public B  // ���� ���
{
public:
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl; // 100���� �϶�


	void(C::*f)(); // ��� �Լ� ������
				   // f ��ü�� ����ü �Դϴ�. { �Լ��ּ�, this_offset }

	cout << sizeof(f) << endl;

	f = &C::fa; // { fa�ּ�, 0}
	//f = &C::fb;// { fb�ּ�, sizeof(A) }
	
	(ccc.*f)(); // ��� �����غ�����
				// f(&ccc + sizeof(A) )

				// f.�Լ��ּ�( &ccc + f.this_offset)
}

// ���� ����..
class Shape
{
public:
	virtual void Draw() = 0;
};

void(Shape::*f)() = &Shape::Draw; // ???



