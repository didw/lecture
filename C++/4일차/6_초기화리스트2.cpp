#include <iostream>
using namespace std;

void foo( initializer_list<int> e )
{
}
int main()
{
	initializer_list<int> e = { 1,2,3,4 };

	foo(e);

	foo({ 1,2,3 });

}