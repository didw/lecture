// 8_�����ڻ�� - 216 page
#include <iostream>
using namespace std;

class Base
{
	int data;
public:
	Base(int n) : data(n) {}
};
class Derived : public Base
{
public:
	// �θ��� ����Ʈ �����ڰ� ������
	// �ڽĻ����ڿ��� �θ� �����ڸ� ��������� ȣ���ؾ� �Ѵ�.
	//Derived(int n) : Base(n) {} // �θ� �������� ����� ȣ��

	// C++11 �θ��� �����ڵ� ��ӵɼ� �ֽ��ϴ�.
	using Base::Base;

	Derived(int n) : Base(0) { cout << "Derived" << endl; }
};

int main()
{
	Derived d(5);
}



