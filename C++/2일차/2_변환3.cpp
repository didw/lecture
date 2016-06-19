// 2_변환3
#include <iostream>
#include <memory>
using namespace std;

class Test
{
	int value;
public:
	explicit Test(int n) : value(n) {}
};

int main()
{
	// 아래 2줄의 차이점을 설명해 보세요
	Test t1(5);  // 인자가 한개인 생성자 호출
	//Test t2 = 5; // 1. 5를 변환생성자를 사용해서 Test의 임시객체 생성
				 // 2. Test 임시객체를 복사 생성자를 사용해서 t2에 복사 

	// C++ 표준의 스마트 포인터 - <memory> 헤더..
	shared_ptr<int> p1 = new int;

	shared_ptr<int> p2( new int );

	// 안드로이드 프레임워크 소스는 String 클래스의 생성자도 explicit 입니다.

	String s1 = "hello";//error
	String s2("hello"); // ok
}






