// 9_�Լ�������- 22 page �̾߱�
#include <iostream>
using namespace std;

class A { public: int a; };
class B { public: int b; };

class C : public A, public B  // ���� ���
{
public: 
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl; // 100������� �Ҷ�

	A* pA = &ccc;  // 100
//	B* pB = &ccc;  // 104

	//B* pB = (B*)&ccc;  // 104


	//B* pB = static_cast<B*>(&ccc);  // 104  &ccc �ּҿ��� B�� ��ġ�� ã�ƶ�
										// ���ϵ� �ּҴ� &ccc�ʹ� �ٸ����� �ִ�.
										// B�� ���ٸ� �������� �����Ƿ� error


	B* pB = reinterpret_cast<B*>(&ccc);  // &ccc �ּҸ� ������ B* �� �����ϰڴ�.
	
	pB->b = 10;

	cout << ccc.a << endl; // 10

	

	cout << pA << endl; // ?
	cout << pB << endl; // ? ��� ������ ������.
}


