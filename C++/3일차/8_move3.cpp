#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 복사 생성자에서는 모든 멤버를 복사로 옮기고
// move 생성자에서는 모든 멤버를 move로 옮긴다.
// 
class Test
{
	string data;
public:
	// 생성자와 소멸자
	Test() { data = "hello"; }
	~Test() {}

	// 복사 생성자와 대입연산자
	Test(const Test& t)   : data(t.data) { cout << "copy" << endl; }
	Test& operator=(const Test& t)       { data = t.data; cout << "copy=" << endl; return *this; }

	// Move 생성자와 Move 대입연산자
	Test(Test&& t) : data(move(t.data))  { cout << "move" << endl; }

	Test& operator=(Test&& t)            { data = move(t.data); cout << "move=" << endl; return *this; }
};



int main()
{

}

