// 9_STL�ٽ�
#include <vector>
#include <list>
#include <string>
#include <algorithm>  // find()���� �Ϲ��Լ��� "�˰���"�̶�� �մϴ�.
#include <iostream>
using namespace std;

int main()
{
	vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// v�� sort()�� ������
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (auto n : v)
		cout << n << endl;


	list<int> s = { 1,3,5,7,9,2,4,6,8,10 };

	// ������ ������
	sort(s.begin(), s.end()); // ??

	for (auto n : s)
		cout << n << endl;

}













