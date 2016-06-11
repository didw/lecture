#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;   


// ��Ģ 2. param Ÿ���� ���� Ÿ���϶�
//         �Լ� ������ ���� �Ӽ��� �����Ѵ�. const, volatile�� ���� �ȴ�.

template<typename T> void foo(T& param)
{
	cout << type_id_with_cvr<T>().pretty_name() << endl;
	cout << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int main()
{
	int n = 1;
	const int c = n;
	int&  r = n;
	const int& cr = c;

	foo(n); // T : int			param : int&
	foo(c); // T : const int	param : const int&
	foo(r); // T : int			param : int&
	foo(cr); // T : const int	param : const int&
}

