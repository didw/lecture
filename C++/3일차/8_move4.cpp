#include <iostream>
#include <string>
#include <vector>
using namespace std;




// 다수의 STL 라이브러리가 move 생성자에 예외가 없을때만 move생성자를사용합니다.
// move 계열 함수를 만들때 꼭 noexcept 를 붙여 주세요..

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

int main()
{
	Test t1;
	Test t2 = t1; // copy
	Test t3 = move(t1); // move 나오게 해보세요..

	Test t4 = move_if_noexcept(t2); // move생성자에 예외가 없을때만 move사용
									// 중요한 개념.
					
}

