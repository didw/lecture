#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;


// �ĺ� 1. ��Ȯ�� Ÿ���� ����.  int a[10]
//         ������ �迭�� ���� �����ɼ� ����.
// 2. �迭�� �̸��� �迭�� 1�� ����� �ּҷ� ��ȯ�ɼ� �ִ�.
//    T�� int*�� �߷��ϸ� �ȴ�.

template<typename T> void foo(T a)  
{
	cout << type_id_with_cvr<T>().pretty_name()           << endl;
	cout << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}
template<typename T> void goo(T& a)  // int(&a)[10]
{
	cout << type_id_with_cvr<T>().pretty_name() << endl;
	cout << type_id_with_cvr<decltype(a)>().pretty_name() << endl;
}
int main()
{
	int x[10] = { 0 };

	foo(x); // T�� Ÿ���� ?
	goo(x);
//	? p = x;
}



