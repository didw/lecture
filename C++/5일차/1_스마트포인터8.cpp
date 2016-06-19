#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

class Car
{
public:
	~Car() { cout << "Car 파괴" << endl; }
};

int main()
{
	weak_ptr<Car> w1;
	{
		shared_ptr<Car> s1(new Car);

		w1 = s1;

	} // s1이 파괴되어서 Car도 파괴 된다. 하지만 아직 w1은 파괴되지 않았다

	// w1을 사용해도 될까 ?
	// 아래 처럼 해도 안됩니다. 멀티스레드 환경이고 다른 스레드가 shared_ptr<>
	// 을 가지고 있을때 문제가 됩니다.
	// 그래서 weak_ptr은 -> 연산자가 재정의 되어 있지 않습니다.
	// 즉, weak_ptr<>로는 Car를 접근할수 없습니다.

	//if ( !w1.expired() )
	//	w1->Go();
	
	// weak_ptr로 원본 객체에 접근하려면 shared_ptr<>을 다시 만들어야 합니다.
	shared_ptr<Car> p3 = w1.lock();

	if (p3)
	{
		// p3사용
	}
	else
	{
		cout << "객체 파괴" << endl;
	}

	// w1으로 객체의 파괴 여부만 조사할수 도 있음.
	if (w1.expired())
		cout << "객체 파괴됨" << endl;

}









