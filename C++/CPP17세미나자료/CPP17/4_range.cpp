// keynote Âü°í..
int main()
{
	// [1,2,3,4,5,6,7,8,9,10]
	auto ra = view::itoa(1, 11);

	cout <<  view::iota(1, 11) << endl;




	// [1,2,3]
	cout << (view::iota(1, 11) | view::take(3)) << endl;


	int x[10] = { 1,2,3,1,2,3,1,2,3,4 };
	
	auto r1 = view::iota(x, x + 10);
	
	auto r2 = r1 | view::take(9); // 1
	auto r3 = r2 | group_by([](int a, int b) { return a == b; });
      // 1 1 1
	  // 2 2 2
	//   3, 3,3
	RANGES_FOR(auto n, r3)
	{
		cout << front(n) << endl; // 1,2,3
	}
}