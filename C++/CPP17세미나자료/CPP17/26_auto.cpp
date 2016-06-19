
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	auto x1{ 1 };	   // int	copy initialize(복사 초기화)
	auto x2 = { 2 };   //  initializer_list<int> list 초기화

	auto x3 = { 1,2 }; // initializer_list<int>
	auto x4{ 1,2 };    // error
}
