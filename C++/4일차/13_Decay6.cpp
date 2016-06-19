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
	foo(hoo); // T 는 ? void(int) 이면 정확한 타입이지만 복사 생성 될수 없다.
			  // 그래서 함수 포인터로 받게 된다.  void(*)(int)

	goo(hoo); // T : void(int)  이면 a는 void(&a)(int)
}



