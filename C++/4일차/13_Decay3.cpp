#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;


// 후보 1. 정확한 타입이 좋다.  int a[10]
//         하지만 배열은 복사 생성될수 없다.
// 2. 배열의 이름은 배열의 1번 요소의 주소로 변환될수 있다.
//    T를 int*로 추론하면 된다.

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

	foo(x); // T의 타입은 ?
	goo(x);
//	? p = x;
}



