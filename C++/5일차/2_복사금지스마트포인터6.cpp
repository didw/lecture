// 2_�����������Ʈ������6
#include <iostream>
#include <memory>
using namespace std;

struct Free
{
	inline void operator()(void* p)
	{
		cout << "Free" << endl;
		free(p);
	}
};

int main()
{
	unique_ptr<int> p1(new int);
	//unique_ptr<int> p2 = p1;    // error.
	unique_ptr<int> p3 = move(p1); // ok..

	// ������ �����ϱ�
	unique_ptr<int[]> p4(new int[10]);
	unique_ptr<int, Free> p5((int*)malloc(100));

	// shared_ptr�� ������
	// �����ڰ� template ���ڿ��ٸ�(�Ʒ�ó��) s1, s2�� �ٸ� Ÿ���� �ȴ�.
	// �ϳ��� �����̳ʿ� �����Ҽ� ����. Ȱ�뵵�� �����ʴ�.
	shared_ptr<int> s1(new int);
	shared_ptr<int[]> s2(new int[10]);

	// �Ʒ� �ڵ忡�� s1, s2�� ���� Ÿ���̴�.
	shared_ptr<int> s1(new int);
	shared_ptr<int> s2(new int[10], foo);

}

