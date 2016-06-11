#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;


// ��Ģ 3. param Ÿ���� Forwarding Reference �϶�

template<typename T> void foo(T&& param)
{
	cout << type_id_with_cvr<T>().pretty_name() << endl;
	cout << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int main()
{
	int n = 10;

	foo(n);		// lvalue �̹Ƿ�  T : int&   T&& : int& && => int&  (param)
	foo(10);	// rvalue �̹Ƿ�  T : int    T&& : int &&  => int&& (param)

	auto n = r; // n int& ? int
}




