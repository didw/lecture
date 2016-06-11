#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;


void hoo(int a) {}


template<typename T> void foo(T a)
{
	cout << type_id_with_cvr<T>().pretty_name() << endl;
	cout << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}
template<typename T> void goo(T& a) 
{
	cout << type_id_with_cvr<T>().pretty_name() << endl;
	cout << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}
int main()
{
	foo(hoo); // T �� ? void(int) �̸� ��Ȯ�� Ÿ�������� ���� ���� �ɼ� ����.
			  // �׷��� �Լ� �����ͷ� �ް� �ȴ�.  void(*)(int)

	goo(hoo); // T : void(int)  �̸� a�� void(&a)(int)
}



