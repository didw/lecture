// 10_template_alias3
#include <iostream>
#include <set>
#include <functional>
using namespace std;

// STL ���� �ڵ尡 �����ϸ� typedef�� �����ϴ�.
//typedef set<int, greater<int>> SET;
//typedef set<double, greater<double>> SET_DOUBLE;

// �Ʒ� ó�� �Ҽ� ������ ? - typedef�� C�����̹Ƿ� template���ȵ�.
//template<typename T> typedef set<T, greater<T>> SET;

// using �� ���ø��� �˴ϴ�.
// "template alias" �Ǵ� "template typedef" ��� �Ҹ��� ����
template<typename T> using SET = set<T, greater<T>>;


int main()
{
//	set<int> s;  // ���������� ������ data�� �� �ϱ� ���� less<>���
	//set<int, greater<int>> s; // greater �Լ���ü�� ����ؼ� ��

	SET<int> s;
	// greater�� ����ؼ� ���ϴ� double Ÿ���� set �ʿ�
	//set<double, greater<double>> s2;
	SET<double> s2;
	s.insert(10);
	s.insert(20);

	SET<int>::iterator p = s.begin();

//	set<int, greater<int>>::iterator p = s.begin();
}






