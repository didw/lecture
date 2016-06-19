#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;   // typeindex 라이브러리는 별도 이름공간사용


// 규칙 1. param 타입이 값 타입일때
//         함수 인자가 가진 const, volatile, reference 속성은 모두 제거한다.
template<typename T> void foo(const T param)
{
	// RTTI의 기술로 T 타입 확인가능
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

