#include <iostream>
#include <boost/type_index.hpp>
using namespace std;
using namespace boost;
using namespace boost::typeindex;
int x = 10;
int& foo() { return x; }

int main()
{
	int n = 10;
	int& r = n;
	auto a1 = r; // ���ø� �߷� ��Ģ
	decltype(r) d1 = r; // r�� ������ �����ؼ� ���.��, ��Ȯ�� Ÿ��..


//	auto ret = foo();

//	decltype(foo()) ret = foo(); // decltype(foo()) �� �Լ� ȣ���� �ƴ϶�
								 // foo()�Լ��� ������ �����϶�� �ǹ�.

	// C++14 : �캯�� ������ Ÿ������, ��, �߷б�Ģ�� decltype() ��Ģ
	decltype(auto) ret = foo();
	ret = 30;


	cout << x << endl;
}







