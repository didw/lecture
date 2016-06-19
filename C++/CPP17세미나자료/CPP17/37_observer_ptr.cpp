#include <memory>
#include <iostream>
using namespace std;

struct NoDelete
{
	void operator()(void* p)const {}
};

int main()
{
	int n = 10;

	observer_ptr<int> p(&n); // 포인터만
					// 보관할뿐 자원관리를 하지 않는다.
	
	unique_ptr<int> p(&n); //



	unique_ptr<int, NoDelete> p1(&n);

	unique_ptr<int, NoDelete> p2 = p1;



}