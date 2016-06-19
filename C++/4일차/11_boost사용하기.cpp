// 11_boost����ϱ�
#include <iostream>

// 1. �ҽ� �ٿ��Ŀ� ���� Ǯ��
// 2. ������ �ϱ�(bootstrap, b2)
// 3. VC++ ���丮 2�� ���� - ���� ���丮(..\boost_1_61_0)
//                            ���̺귯�� ���丮(..\boost_1_61_0\stage\lib)
// 4. ���ϴ� ��� ���� �߰�
// 5. using namesapce boost;

#include <boost\any.hpp>
using namespace std;
using namespace boost;

int main()
{
	// boost any : ���� ��� Ÿ���� ��� ��ü.
	any a = 10;
	any b = 3.4;
	any c = "hello";

	int n = any_cast<int>(a);

	const char* s = any_cast<const char*>(c);

	cout << s << endl;
}
