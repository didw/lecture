struct B1 {
	B1() {}
	B1(int) {}
};

struct B2 {
	B2() {}
	B2(int) {}
};
/*
struct D1 : B1, B2 {
	using B1::B1;
	using B2::B2;
};
*/

struct D2 : B1, B2 {
	using B1::B1;
	using B2::B2;
	D2(int) {}   // OK: D2::D2(int) hides B1::B1(int) and B2::B2(int)
};
int main()
{
//	D1 d1(0);    // ill-formed: ambiguous
	D2 d2(0);    // calls D2::D2(int)
}
