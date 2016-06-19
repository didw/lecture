// 2_복사금지스마트포인터6
#include <iostream>
#include <memory>
using namespace std;

struct Free
{
	inline void operator()(void* p)
	{
		cout << "Free" << endl;
		free(p);
	}
};

int main()
{
	unique_ptr<int> p1(new int);
	//unique_ptr<int> p2 = p1;    // error.
	unique_ptr<int> p3 = move(p1); // ok..

	// 삭제자 변경하기
	unique_ptr<int[]> p4(new int[10]);
	unique_ptr<int, Free> p5((int*)malloc(100));

	// shared_ptr의 삭제자
	// 삭제자가 template 인자였다면(아래처럼) s1, s2는 다른 타입이 된다.
	// 하나의 컨테이너에 보관할수 없다. 활용도가 좋지않다.
	shared_ptr<int> s1(new int);
	shared_ptr<int[]> s2(new int[10]);

	// 아래 코드에서 s1, s2는 같은 타입이다.
	shared_ptr<int> s1(new int);
	shared_ptr<int> s2(new int[10], foo);

}

