#include <algorithm>
#include <experimental/iterator>
#include <iostream>
#include <iterator>
using namespace std;

// C++98 의 ostream_iterator 의 개선 버전.
int main()
{
	ostream_iterator<int> p(cout);

	*p = 50; // cout << 50 << endl;


	int i[] = { 1, 2, 3, 4, 5 };
	copy(std::begin(i), end(i),
		      make_ostream_joiner(std::cout, ", "));
}

// 1, 2, 3, 4, 5