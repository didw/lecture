#include <memory>
#include <iostream>
using namespace std;

struct NoDelete
{
	void operator()(void* p)const {}
};

int main()
{
	int n = 10;

	observer_ptr<int> p(&n); // �����͸�
					// �����һ� �ڿ������� ���� �ʴ´�.
	
	unique_ptr<int> p(&n); //



	unique_ptr<int, NoDelete> p1(&n);

	unique_ptr<int, NoDelete> p2 = p1;



}