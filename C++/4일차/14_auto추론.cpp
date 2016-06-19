// 14_auto추론
#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;

int main()
{
	int n = 10;
	int& r = n;
	const int c = n;

	// T param = 함수인자
	auto n2 = c; // int
	auto n3 = r; // int
	auto& n4 = c;// const int&

	int x[10] = { 0 };
	auto  p  = x; // int*
	auto& r2 = x; // int(&r2)[10]

	// 주의 : 템플릿 함수 인자(auto의 우변)의 상수성만 제거.
	const char* const s = "hello";

	auto s2 = s; //  s2의 타입은? const char*
				 // s는 const가 아니다.. s가 가르키는 곳이 const이다.

	cout << type_id_with_cvr<decltype(s2)>().pretty_name() << endl;
}
// boost 헤더 복사해오세요..





