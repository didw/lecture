// 2_static_assert- 186 page

#include <iostream>
#include <cassert>   // assert()�� ����
using namespace std;


// C++11 ������ �ð� assert ����
static_assert(sizeof(double) > 8, "error. double�� 8����Ʈ�̻��϶��� �����ϵ�");


void foo(int age)
{
	// ���ڸ� ����ϱ� ���� ���ڰ��� ��ȿ���� Ȯ���ϴ� ���� ����.
	assert(age > 0);
	
	int* p = new int[age]; 
}
int main()
{
	foo(-10);
}




