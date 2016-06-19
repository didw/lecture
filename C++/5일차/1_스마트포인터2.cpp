#include <iostream>
using namespace std;

// Ptr�� �����ؿ�����
// 1. template ���� �ؾ� �Ѵ�.
template<typename T> class Ptr
{
	T* obj;

	int* ref; // ��������� ����ų ������
public:
	Ptr(T* p = 0) : obj(p) 
	{
		ref = new int(1); // �Ѱ��� 1�� �ʱ�ȭ
	}

	// ���� ������
	Ptr(const Ptr& p)
	{
		// ���� ���� �Ŀ�
		obj = p.obj;
		ref = p.ref;

		// ������� ����
		++(*ref);
	}

	~Ptr() 
	{
		// ��������� 0�̸� �ڿ��� ������� ����
		if (--(*ref) == 0)
		{
			delete obj;
			delete ref;
		}
	}

	T* operator->() { return obj; }
	T& operator*() { return *obj; }
};
int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;

	Ptr<int> p2 = p1; // ���� ������
}