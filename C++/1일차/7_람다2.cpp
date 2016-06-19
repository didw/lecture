#include <iostream>
#include <functional>
using namespace std;

int main()
{
	int x[10] = { 1,2,3 };


	sort(x, x + 10, [](int a, int b) { return a < b;});
	/*
	// ���ڵ带 ���� C++ �����Ϸ��� �Ʒ� �ڵ带 �����մϴ�.
	class LambdaClass  // Ŭ���� �̸��� �����Ϸ��� ������ ���ϰ� �˴ϴ�.
	{
	public:
		inline bool operator()(int a, int b) const
		{
			return a < b;
		}

	};
	//LambdaClass closure;
	//sort(x, x + 10, closure);

	sort(x, x + 10, LambdaClass()); // Ŭ�����̸�() : �ӽð�ü�� �����ϴ� ǥ��
								// �ӽð�ü�� �𸣽ø� �� �ڵ�ó�� �����ϼ���
	*/
}




