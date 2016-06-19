// 4_trivial
#include <iostream>
using namespace std;

// trivial(자명한) 생성자 : 아무일도 하지 않은 생성자

// 1. 가상함수가 없고
// 2. 부모가 없거나 부모의 생성자가 trivial 하고
// 3. 객체형 멤버가 없거나 객체형 멤버의 생성자가 trivial 하고
// 4. 사용자가 만든 생성자가 없다면 

// "생성자는 trivial 하다"


class A {};

class B// : public A
{
	//A a;
public:

	//virtual void foo() { cout << "foo" << endl; }
};

// B의 생성자는 trivial 할까 ?
int main()
{
	B* p = static_cast<B*>( malloc(sizeof(B)) );

	new(p) B; // p에 대해 생성자 호출

	p->foo();

}




