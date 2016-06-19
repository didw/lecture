// 33_optional

#include <iostream>
#include <boost/optional.hpp>
using namespace std;
using namespace boost;
/*
int foo(char* s)
{
	// s���ڿ��� ���ڷ� �����ؼ� ����..
}

int n = foo("xxx");
*/
pair<bool, int>
optional<int> getConfigParam(std::string name)
{
	if (name == "fail")
		return boost::none;

	return atoi(name.c_str());
}

int main()
{
	if (boost::optional<int> oi = getConfigParam("fail")) // did I get a real int?
		cout << *oi << endl; // 120
	else
		cout << "fail" << endl;
}

