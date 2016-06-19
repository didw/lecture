// 35_propagate_const
#include <iostream>
using namespace std;

struct X
{
	void g() const { std::cout << "g (const)\n"; }
	void g()       { std::cout << "g (non-const)\n"; }
};
	 
struct Y
{
	//X* m_ptrX; //
	propagate_const<X*> m_ptrX; //

	Y() : m_ptrX( new X) { }

	void f() const
	{
		std::cout << "f (const)\n";
		m_ptrX->g();  // X const* m_ptrX;
	}
	void f()
	{
		std::cout << "f (non-const)\n";
		m_ptrX->g();
	}
};

int main()
{
	Y y;
	y.f(); // 일반함수 

	const Y cy;
	cy.f(); // 상수 버전
}