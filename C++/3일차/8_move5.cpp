#include <iostream>
#include <string>
#include <vector>
using namespace std;



class Test
{
	string data;
public:
	Test() { data = "hello"; }
	~Test() {}
	Test(const Test& t) : data(t.data) { cout << "copy" << endl; }
	Test& operator=(const Test& t) { data = t.data; cout << "copy=" << endl; return *this; }


	Test(Test&& t) noexcept : data(move(t.data)) { cout << "move" << endl; }
	Test& operator=(Test&& t) noexcept { data = move(t.data); cout << "move=" << endl; return *this; }
};

// Big 5 : 소멸자, 복사 생성자, 복사 대입연산자, move 생성자, move 대입연산자

// 규칙 1. Big5중 하나도 만들지 않으면 컴파일러가 모두 만들어 준다.

//      2. RuleOf3 : 소멸자, 복사 생성자, 대입연산자중 하나만 제공해도..
//				     나머지 2개는 컴파일러 만들어 준다. 즉, 독립적으로 동작
//                   move는 제공 안함. => 하지만 복사생성자를 사용해서 move

//    3. move 계열 함수를 제공하면 복사 계열 함수는 제공 되지 않는다.
//	     반드시 사용자가 만들어야 한다.

// 결론..
// 하나의 클래스에 복사 계열만 제공할수는 있다.
//	   복사 생성자로 move를 해도 되므로..

// move계열 함수만 제공할수는 없다.
//     move 생성자로 복사를 할수는 없으므로..

class Object
{
	string data;
	Test t;
public:
	Object() {}
	~Object() {}

	Object(Object&& o) : t(move(o.t)), data(move(o.data)) {}
};

int main()
{
	Object o1;
	Object o2 = o1;			// copy
	Object o3 = move(o1);	// move

	o3 = o2;
	o3 = move(o2);
}

