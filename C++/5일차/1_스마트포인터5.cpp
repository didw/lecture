#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// 멤버로 new를 제공 - Point만들때는 아래 함수 사용해 달라는것 
	// - 메모리 풀링 기술에서 널리사용
	static void* operator new(size_t sz)
	{
		cout << "Point::new" << endl;
		return malloc(sz);
	}
};

void* operator new(size_t sz)
{
	cout << "new" << endl;
	return malloc(sz);
}

void operator delete(void* p) { 	free(p);}

int main()
{
//	shared_ptr<Point> p1(new Point(1, 2)); // 이순간 메모리 할당이 몇번 일어
											// 나는지 생각해 보세요.

	// 관리 객체를 실제 객체에 붙여서 메모리 할당
	shared_ptr<Point> p1 = make_shared<Point>(1, 2);

	// make_shared 를 사용할때는 사용자 정의 삭제자를 사용할수 없다.!

	//foo(p1);
	//foo(make_shared<Point>(1, 2))
}


/*
// make_shared의 원리
template<typename T, typename ... Types> 
shared_ptr<T> make_shared(Types&& ... args )
{
	// 1. 메모리 할당.
	void* p = ::operator new(sizeof(T) + sizeof(관리객체));

	// 메모리의 앞부분은 객체이다. 생성자를 호출해야 한다.
	new(p) T(args...); // placement new + 완벽한 전달자로 전달..

	T* obj = static_cast<T*>(p);
	관리객체* ref = static_cast<관리객체*>((char*)obj + sizeof(T));

	shared_ptr<T> ret;
	ret.reset(obj, ref);
	return ret;
}
*/

















