// 3_thiscall2


// 15page
// 1. �Ϲ� �Լ� �����Ϳ� ��� �Լ��� �ּҸ� ������ ����.
// 2. �Ϲ� �Լ� �����Ϳ� static ��� �Լ��� �ּҸ� ������ �ִ�. 
// 3. ����Լ� �����͸� ����� ����ϴ� ���
//    - �Ʒ� main ����, ���� 15 page ����.

class Dialog
{
public:
	void Close() {}
};

void foo() {}

int main()
{
	void(*f1)() = &foo; // ok
	//void(*f2)() = &Dialog::Close; // �ɱ�� ??

	// ��� �Լ� ������ ����� ��

	void(Dialog::*f2)() = &Dialog::Close; // 

	//f2(); // �ɱ�� ? error. this�� ����.

	Dialog dlg;
	(dlg.*f2)();  // �ᱹ dlg.Close()�Դϴ�...

}






