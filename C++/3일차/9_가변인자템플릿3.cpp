#include <iostream>
using namespace std;

// �������� ������ ����ϱ� - �߿�!!

// �ٽ� 1. 1��° ���ڴ� �ݵ�� ������ �Ϲ� ������ �޾ƾ� �Ѵ�.
//      2. ��� ȣ��� ������ ������� ������ ���ڸ� ������  �ȴ�.
//         ��� ȣ���� �ƴϴ�.


template<typename T, typename ... Types> 
void foo(T value, Types ... args)
{
	static int n = 0;
	++n;

	cout << n << " : " << typeid(T).name() << " : " << value << endl;

	foo(args...);   // foo(3.4, 4)  value : 3.4  args : 4
					// foo(4)       value : 4    args : 
					// foo()
}

void foo() {}

int main()
{
	foo(1, 3.4, 4); // value : 1    args : 3.4  4
}









