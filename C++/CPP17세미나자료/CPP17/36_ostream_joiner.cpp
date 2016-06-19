#include <algorithm>
#include <experimental/iterator>
#include <iostream>
#include <iterator>
using namespace std;

// C++98 �� ostream_iterator �� ���� ����.
int main()
{
	ostream_iterator<int> p(cout);

	*p = 50; // cout << 50 << endl;


	int i[] = { 1, 2, 3, 4, 5 };
	copy(std::begin(i), end(i),
		      make_ostream_joiner(std::cout, ", "));
}

// 1, 2, 3, 4, 5