// 4_trivial
#include <iostream>
using namespace std;

// trivial(�ڸ���) ������ : �ƹ��ϵ� ���� ���� ������

// 1. �����Լ��� ����
// 2. �θ� ���ų� �θ��� �����ڰ� trivial �ϰ�
// 3. ��ü�� ����� ���ų� ��ü�� ����� �����ڰ� trivial �ϰ�
// 4. ����ڰ� ���� �����ڰ� ���ٸ� 

// "�����ڴ� trivial �ϴ�"


class A {};

class B// : public A
{
	//A a;
public:

	//virtual void foo() { cout << "foo" << endl; }
};

// B�� �����ڴ� trivial �ұ� ?
int main()
{
	B* p = static_cast<B*>( malloc(sizeof(B)) );

	new(p) B; // p�� ���� ������ ȣ��

	p->foo();

}




