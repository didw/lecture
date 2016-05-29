// 8_value_type
#include <vector>
#include <list>
#include <iostream>
using namespace std;

/*
void print(vector<int>& v)
{
	int n = v.front();

	cout << n << endl;
}
*/
/*
template<typename T> void print(vector<T>& v)
{
	T n = v.front();

	cout << n << endl;
}
*/

template<typename T> void print(T& v)
{
	// T               => list<double> 
	// T::value_type   => double

	// C++98/03 ����
	//typename T::value_type n = v.front();


	// C++11 ����. - 87 page
	auto n = v.front();

	cout << n << endl;
}



int main()
{
	list<double> v(10, 3); // 10���� 3����

	print(v);
}

// ���ø� ����� ��� �����̳ʴ� �ڽ��� �����ϴ� Ÿ���� �ִ�.
// �ܺο��� �� Ÿ���� �˰� �������� �ִ�. - ���� print()
/*
// �׷��� �Ʒ�ó�� ������ �Ѵ�.
template<typename T> class list
{
public:
	typedef T value_type;  // �ٽ�!!!
	//.....
};

list<int> s(10, 3);

list<int>::value_type n = s.front(); // n�� �ᱹ int �Դϴ�.
*/





