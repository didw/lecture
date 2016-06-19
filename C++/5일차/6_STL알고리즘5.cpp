// 6_STL�˰���
#include <iostream>
using namespace std;



// Step 5. ������ ���� : 0 ��� last ����.

// ��� Ÿ���� �迭 [first, last) �������� ���� �˻� ����.
// last �� �˻� ����� �ƴ�.

template<typename T1, typename T2> T1 xfind(T1 first, T1 last, T2 value)
{
	while (first != last && *first != value)
		++first;
	return first;// == last ? 0 : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = xfind(x, x + 10, 5);

	if (p == x + 10 )
		cout << "ã���� �����ϴ�." << endl;
	else
		cout << *p << endl;
}

