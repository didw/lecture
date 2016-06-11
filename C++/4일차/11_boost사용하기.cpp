// 11_boost사용하기
#include <iostream>

// 1. 소스 다운후에 압축 풀고
// 2. 컴파일 하기(bootstrap, b2)
// 3. VC++ 디렉토리 2개 설정 - 포함 디렉토리(..\boost_1_61_0)
//                            라이브러리 디렉토리(..\boost_1_61_0\stage\lib)
// 4. 원하는 헤더 파일 추가
// 5. using namesapce boost;

#include <boost\any.hpp>
using namespace std;
using namespace boost;

int main()
{
	// boost any : 거의 모든 타입을 담는 객체.
	any a = 10;
	any b = 3.4;
	any c = "hello";

	int n = any_cast<int>(a);

	const char* s = any_cast<const char*>(c);

	cout << s << endl;
}
