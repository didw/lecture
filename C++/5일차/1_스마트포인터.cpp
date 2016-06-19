// 1_스마트포인터
#include <iostream>
using namespace std;

class Car
{
public:
	void Go() { cout << "Car Go" << endl; }
	~Car()    { cout << "Car 파괴" << endl; }
};
// 아래 코드가 핵심입니다.
// 스마트 포인터 개념
// 임의의 객체가 다른 타입의 포인터 역활을 하는것
// 원리 : -> 연산자와 * 연산자를 재정의해서 포인터 처럼 보이게 한다.
// 장점 : 진짜 포인터가 아니라 객체이다. 생성/복사/대입/소멸의 모든 과정을 제어할수
//        있다. 대표적인 기능이 소멸자에서 자원 관리.

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}

	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*()  { return *obj; }
};
int main()
{
	Ptr p = new Car; // Ptr p( new Car )로 생각하는게 쉽습니다.
	p->Go();         // ( p.operator->() ) Go() 의 모양이지만
					 // ( p.operator->() )->Go()로 해석 됩니다.	
	(*p).Go();
}






