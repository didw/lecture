// 1_����Ʈ������
#include <iostream>
using namespace std;

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car()    { cout << "Car �ı�" << endl; }
};
// �Ʒ� �ڵ尡 �ٽ��Դϴ�.
// ����Ʈ ������ ����
// ������ ��ü�� �ٸ� Ÿ���� ������ ��Ȱ�� �ϴ°�
// ���� : -> �����ڿ� * �����ڸ� �������ؼ� ������ ó�� ���̰� �Ѵ�.
// ���� : ��¥ �����Ͱ� �ƴ϶� ��ü�̴�. ����/����/����/�Ҹ��� ��� ������ �����Ҽ�
//        �ִ�. ��ǥ���� ����� �Ҹ��ڿ��� �ڿ� ����.

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; }
};
int main()
{
	Ptr p = new Car; // Ptr p( new Car )�� �����ϴ°� �����ϴ�.
	p->Go();         // ( p.operator->() ) Go() �� ���������
					 // ( p.operator->() )->Go()�� �ؼ� �˴ϴ�.	
	(*p).Go();
}






