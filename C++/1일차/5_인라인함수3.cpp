// 5_�ζ����Լ�3
#include <algorithm>
using namespace std;

// ���̺귯�� �����ڸ� ������ ���ô�.
// 1. ����. ����� �Ѵ�.
// 2. ������. ��å ������ �����ؾ� �Ѵ�.

// ���뼺�� �������� ��Ģ
// ������ ���� ��ü���� �˰��򿡼� ���ؾ� �ϴ� �κ�(��å)�� �ִٸ� 
// �и��� ���� �Ѵ�.

// �Ϲ� �Լ��� ��� : ���ϴ� ���� �Լ� ���ڷ� �̾Ƴ���(�Լ� ������)



void Sort(int* x, int n, bool(*cmp)(int,  int) ) // C����� qsort()����
{
	for (int i = 0; i < n - 1; i++)

		for (int j = i + 1; j < n; j++)

//			if ( x[i] > x[j] )     // 1

			if( cmp(x[i], x[j]) )  // 2
				swap( x[i], x[j] );
}
//----------------------------------------
// �� ��å�� ���� �Լ��� 

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }




int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	
	Sort(x, 10, cmp1);
	Sort(x, 10, cmp2);
}
// 25page �Դϴ�.



