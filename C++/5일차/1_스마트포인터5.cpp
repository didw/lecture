#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) {}

	// ����� new�� ���� - Point���鶧�� �Ʒ� �Լ� ����� �޶�°� 
	// - �޸� Ǯ�� ������� �θ����
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
//	shared_ptr<Point> p1(new Point(1, 2)); // �̼��� �޸� �Ҵ��� ��� �Ͼ�
											// ������ ������ ������.

	// ���� ��ü�� ���� ��ü�� �ٿ��� �޸� �Ҵ�
	shared_ptr<Point> p1 = make_shared<Point>(1, 2);

	// make_shared �� ����Ҷ��� ����� ���� �����ڸ� ����Ҽ� ����.!

	//foo(p1);
	//foo(make_shared<Point>(1, 2))
}


/*
// make_shared�� ����
template<typename T, typename ... Types> 
shared_ptr<T> make_shared(Types&& ... args )
{
	// 1. �޸� �Ҵ�.
	void* p = ::operator new(sizeof(T) + sizeof(������ü));

	// �޸��� �պκ��� ��ü�̴�. �����ڸ� ȣ���ؾ� �Ѵ�.
	new(p) T(args...); // placement new + �Ϻ��� �����ڷ� ����..

	T* obj = static_cast<T*>(p);
	������ü* ref = static_cast<������ü*>((char*)obj + sizeof(T));

	shared_ptr<T> ret;
	ret.reset(obj, ref);
	return ret;
}
*/

















