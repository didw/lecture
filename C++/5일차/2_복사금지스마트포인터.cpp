// 2_�����������Ʈ������
#include <iostream>
using namespace std;

template<typename T> class Ptr
{
	T* obj;
	Ptr(const Ptr&) = delete;
	void operator=(const Ptr&) = delete;
public:
	inline Ptr(T* p = 0) : obj(p) {}
	inline ~Ptr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main()
{
	Ptr<int> p1 = new int;
	*p1 = 10;
	cout << *p1 << endl;

//	Ptr<int> p2 = p1; // ���� ������
}
