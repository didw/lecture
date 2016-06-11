#include <iostream>
using namespace std;

#pragma pack(1)     // ����ü align�� 1����Ʈ ������(�����Ͻÿ� �ɼ����ε� ����)
struct PACKET
{
	char cmd;
	int  data;
};
static_assert(sizeof(PACKET) == sizeof(char) + sizeof(int),
						"error. unexpected padding");

//------------------
#include <type_traits>
template<typename T> void foo(T* p)
{
	static_assert(!is_polymorphic<T>::value, "error T has virtual function");

	memset(p, 0, sizeof(T)); // ???
}

class A 
{
	int a;
public:
	virtual void goo() {}
};

int main()
{
	A a;
	foo(&a);
	//cout << sizeof(PACKET) << endl;
}





