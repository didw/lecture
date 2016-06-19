#include <vector>
#include <algorithm>
using namespace std;

class Test
{
public:
	void foo(int a) {}
};

int main()
{
	Test t;
	t.foo(10); //foo(&t, 10);

	foo(t, 10); // ¿Ã∂ß t.foo(10)


	vector<int> v1;
	vector<int> v2;

	v1.swap(v2);
	swap(v1, v2);




	Test t;
	t.foo(1); // ok ..
	foo(t, 1);// ok in C++ 17
}