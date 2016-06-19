#include <iostream>
#include <iomanip>
#include <memory>
#include <algorithm>
using namespace std;

int main()
{
	// 1. register
	register int a;  

	// 2. bool increment
	bool b = 0;
	++b;  //	bool increment

	// 3. auto_ptr
	auto_ptr<int> ap;

	// 4. random_shuffle
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	random_shuffle(x, x + 10);
}