// 2_복사금지스마트포인터
#include <iostream>
using namespace std;

template<typename T> class UniquePtr
{
	T* obj;
	UniquePtr(const UniquePtr&) = delete;
	void operator=(const UniquePtr&) = delete;
public:
	inline explicit UniquePtr(T* p = 0) : obj(p) {}
	inline ~UniquePtr() { delete obj; }
	inline T* operator->() { return obj; }
	inline T& operator*() { return *obj; }
};

int main()
{
	UniquePtr<int> p1(new int);
}
