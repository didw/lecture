// 6_�Լ���ü3
#include <iostream>
#include <algorithm> // �̾ȿ� �̹� sort()�� �ֽ��ϴ�.
using namespace std;

// �ζ����Լ� 3���� cmp1, cmp2, �����ؿ�����
// Less, Greater ���� �ؿ�����

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// sort�� 3��° ���ڴ� ���ø� �Դϴ�

	// 1. ��å���� �Ϲ��Լ��� ����Ҷ�
	
	// ���� : ��å�� ��ü�ص� sort() ���� �ڵ�� �Ѱ� �̴�. �޸� ��뷮��������
	// ���� : ��å �Լ��� �ζ��� ġȯ �ɼ� ����. ������.

	sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int, int)) �� �Լ�����
	sort(x, x + 10, cmp2); // sort(int*, int*, bool(*)(int, int)) �� �Լ�����

	// 2. ��å���� �Լ���ü�� ����Ҷ�

	// ���� : ��å�� ��ü�ϸ� sort() ���� �ڵ�� ������ �̴�. �޸� ��뷮����
	// ���� : ��å �Լ��� �ζ��� ġȯ �ɼ� �ִ�.

	Less    f1;
	Greater f2;
	sort(x, x + 10, f1); // sort( int*, int*, Less) �� �Լ� ����
	sort(x, x + 10, f2); // sort( int*, int*, Greater) �� �Լ� ����
}

// 28 page ...


