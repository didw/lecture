// cafe.naver.com/cppmaster 넥슨 게시판에서 자료 받으실수 있습니다.

// https://github.com/CppCon 작년 9월 미국에서 열린 C++ 컨퍼런스 자료 있습니다.


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