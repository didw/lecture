// cafe.naver.com/cppmaster �ؽ� �Խ��ǿ��� �ڷ� �����Ǽ� �ֽ��ϴ�.

// https://github.com/CppCon �۳� 9�� �̱����� ���� C++ ���۷��� �ڷ� �ֽ��ϴ�.


#include <iostream>
#include <experimental\filesystem>
using namespace std;
using namespace experimental::filesystem;

int main()
{
	path p("38_file_system.cpp");  

	if (exists(p))    
	{
		if (is_regular_file(p))        
			cout << p << " size is " << file_size(p) << '\n';

		else if (is_directory(p))     
			cout << p << " is a directory\n";
		else
			cout << p << " exists, but is not a regular file or directory\n";
	}
	else
		cout << p << " does not exist\n";

	return 0;
}