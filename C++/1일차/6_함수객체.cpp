// 6_�Լ���ü
#include <iostream>
using namespace std;


// �Լ� ��ü : ()�����ڸ� ������ �ؼ� �Լ� ó�� ��밡���� ��ü
//			Functor ��� �θ���.!
//			() ������ �Լ��� ��κ� ��� �Լ��� ����� �ȴ�.

class Plus
{
public:
	int operator()(int a, int b) const
	{
		return a + b;
	}
};


int main()
{
	Plus p;
	int n = p(1, 2); // ?
	cout << n << endl; // 3

	// a + b; // a.operator+ ( b )
	// a - b; // a.operator- ( b ) 
	// a();   // a.operator()()
	// a(1,2);// a.operator()(1,2)

}// 26 page

