// 9_���ø��κ�����ȭ2

#include <iostream>
using namespace std;

template<typename T, typename U> class Pair
{
public:
	void foo() { cout << "T,U" << endl; }
};

// �κ� ����ȭ �Ҷ� ���ø� ������ ������ primary template�� �ٸ����� �ֽ��ϴ�.
template<typename T> class Pair<short, T>
{
public:
	void foo() { cout << "short, T" << endl; }
};

template<typename T> class Pair<T, T>
{
public:
	void foo() { cout << "T, T" << endl; }
};

template<typename T, typename U> class Pair<T*, U>
{
public:
	void foo() { cout << "T*, U" << endl; }
};

int main()
{
	Pair<int,    double> p1; p1.foo();
	Pair<short,  double> p2; p2.foo();
	Pair<double, double> p3; p3.foo(); // �ΰ��� Ÿ���� ������
	Pair<char*,  double> p4; p4.foo(); // 1��°�� �������̰�, 2��° �����Ͱ� �ƴѰ��
}





