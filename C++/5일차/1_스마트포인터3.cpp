#include <iostream>
using namespace std;

// C++표준에 이미 참조계수 기반 스마트 포인터가 있습니다.
#include <memory>

int main()
{
	//shared_ptr<int> p1 = new int; // error

	shared_ptr<int> p1(new int); // ok.. explicit 생성자

	shared_ptr<int> p2 = p1; // 이순간 참조계수가 증가 합니다.
}