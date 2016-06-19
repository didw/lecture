#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;   // typeindex ���̺귯���� ���� �̸��������


// ��Ģ 1. param Ÿ���� �� Ÿ���϶�
//         �Լ� ���ڰ� ���� const, volatile, reference �Ӽ��� ��� �����Ѵ�.
template<typename T> void foo(const T param)
{
	// RTTI�� ����� T Ÿ�� Ȯ�ΰ���
//	cout << typeid(T).name() << endl;
//	cout << typeid(param).name() << endl;

	cout << type_id_with_cvr<T>().pretty_name() << endl;
	cout << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}



int main()
{
	int n = 1;
	const int c = n;
	int&  r = n;
	const int& cr = c;

	foo(n); // T : int  param : const int
	foo(c); // T : int  param : const int
	foo(r); // T : int  param : const int
	foo(cr); // T : int param : const int
}

