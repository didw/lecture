
#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	auto x1{ 1 };	   // int	copy initialize(���� �ʱ�ȭ)
	auto x2 = { 2 };   //  initializer_list<int> list �ʱ�ȭ

	auto x3 = { 1,2 }; // initializer_list<int>
	auto x4{ 1,2 };    // error
}
