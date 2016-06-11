#include <iostream>
using namespace std;
/*
// const �� ���ؼ�
// 1. const�� Ÿ���� �� �Ǵ� �ڿ� ���ϼ� �ֽ��ϴ�.  c1, c2�� �����մϴ�.
const int c1 = 10;
int const c2 = 10;  

// 2. ��� �����Ϳ� ������ ���
const int* p1 = &c1; // p1�� ���󰡸� ���. "����� ����Ű�� ������"
int const* p2 = &c1; // p1, p2�� ����
int* const p3 = &c1; // ������ ��ü�� ���.
*/



template<typename T> class Base
{
public:
	// "T�� ����̴�"
	//virtual void foo(const T a) { cout << "Base foo" << endl; }

	virtual void foo(T const a) { cout << "Base foo" << endl; }
};

class Derived : public Base<int*>
{
public:
	// foo ������ �ؼ� Derived foo ������ �غ�����.. - override ������� ������
	// "int*�� ����̴�"
	//virtual void foo(const int* a) { cout << "Derived foo" << endl; }

	virtual void foo( int* const a) { cout << "Derived foo" << endl; }
};
int main()
{
	Base<int*>* p = new Derived;

	p->foo(0);  // "Derived foo" ���;� �մϴ�.
}





