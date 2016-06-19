// 7_typename
class AAA
{
public:
	//......
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

template<typename T> typename T::DWORD foo(T a)
{
	typename T::DWORD * p; // 이 코드를 해석해 보세요
				// 1. DWORD는 static 멤버 데이타 인데 곱하기 p
				// 2. DWORD는 T에 내포된 타입(typedef등)이다.
				//    포인터 변수 p를 선언하고 있다.

	return 0;
}
int main()
{
	AAA aaa;
	foo(aaa);
}
// 85page

