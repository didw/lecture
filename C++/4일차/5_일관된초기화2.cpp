
int main()
{
	int n1 = 3.4; // ok

	int n2{ 3.4 }; // error. "preventing narrow"

	char c1{ 100 }; // ok

	char c2{ 300 }; // error
}
// www.boost.org
