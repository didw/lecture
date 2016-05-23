// 9_함수포인터- 22 page 이야기
#include <iostream>
using namespace std;

class A { public: int a; };
class B { public: int b; };

class C : public A, public B  // 다중 상속
{
public: 
	int c;
};

int main()
{
	C ccc;
	cout << &ccc << endl; // 100번지라고 할때

	A* pA = &ccc;  // 100
//	B* pB = &ccc;  // 104

	//B* pB = (B*)&ccc;  // 104


	//B* pB = static_cast<B*>(&ccc);  // 104  &ccc 주소에서 B의 위치를 찾아라
										// 리턴된 주소는 &ccc와는 다를수도 있다.
										// B가 없다면 연관성이 없으므로 error


	B* pB = reinterpret_cast<B*>(&ccc);  // &ccc 주소를 무조건 B* 로 생각하겠다.
	
	pB->b = 10;

	cout << ccc.a << endl; // 10

	

	cout << pA << endl; // ?
	cout << pB << endl; // ? 결과 예측해 보세요.
}


