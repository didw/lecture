
#include <iostream>
using namespace std;
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

//#include <experimental\filesystem>
//using namespace std::experimental::filesystem;


int main(int argc, char* argv[])
{
	path p("38_file_system.cpp");  // avoid repeated path construction below

	if (exists(p))    // does path p actually exist?
	{
		if (is_regular_file(p))        // is path p a regular file?
			cout << p << " size is " << file_size(p) << '\n';

		else if (is_directory(p))      // is path p a directory?
			cout << p << " is a directory\n";

		else
			cout << p << " exists, but is not a regular file or directory\n";
	}
	else
		cout << p << " does not exist\n";

	return 0;
}
