// 3_const3
int main()
{
	int n = 10;

	constexpr int c1 = 10; // ok.
	constexpr int c2 = n; // error

	const int c3 = 10;
	const int c4 = n; 
}