// 15_decltype2

int main()
{
	int n = 10;
	int* p = &n;

	int x[4] = { 1,2,3,4 };
	
	// �� Ÿ�� �߷��غ�����
	// foo() = ��, �� �Լ� ȣ���� lvalue�� �Ƿ��� ���� ������ �ʿ� �ϴ�.
	// ������ ����� �º��� �ü� �ִ����� �����ض�.!
	decltype(n)    d1; // int
	decltype(p)    d2; // int*
	decltype(*p)   d3 = n; // int&
	d3 = 100;
	decltype(x[0]) d4; // int&

	decltype(++n)  d5; // int&   // ++n = 3 .. ok.. �����ϴ�. ++(++n)
	decltype(n++)  d6; // int
	decltype(n+n)  d7; // n + n = 3; ó�� �º��� �ü� ����. 
					   // int�� �߷� 
}




