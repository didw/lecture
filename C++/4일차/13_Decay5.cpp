#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;

typedef void FUNC(int);  // FUNC�� �Լ� Ÿ��
typedef void(*PFUNC)(int); // �Լ� ������ Ÿ��

void foo(int a) {}

int main()
{
	void(*f1)(int) = &foo; // ��Ȯ�� ǥ��
	void(*f2)(int) = foo; // �Լ��� �̸��� �Լ� �ڵ� ù��° �ּҷ� �Ͻ��� ����ȯ

	PFUNC f3 = &foo;
	FUNC* f4 = &foo;
	FUNC* f5 = foo;

	FUNC f6 = foo; // error. �Լ��� �迭ó�� ���� �����ɼ� ����.

	FUNC& r = foo; // ok
}









