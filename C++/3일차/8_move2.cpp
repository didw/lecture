#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test
{
	string data;
public:
	// 생성자와 소멸자
	Test()  { data = "hello"; }
	~Test() {}

	// 복사 생성자와 대입연산자
	Test(const Test& t)            { cout << "copy" << endl; }
	Test& operator=(const Test& t) { cout << "copy=" << endl; return *this; }

	// Move 생성자와 Move 대입연산자
	Test(Test&& t)            { cout << "move" << endl; }
	Test& operator=(Test&& t) { cout << "move=" << endl; return *this; }
};

// swap
template<typename T> void Swap(T& a, T& b)
{
	T temp = move(a);
	a = move(b);
	b = move(temp);
}

int main()
{
	vector<Test> v(10); 

	v.resize(20); // 버퍼 키우기..



	Test t1, t2;
	Swap(t1, t2);

//	Test t1;
//	Test t2 = t1; // 복사
//	t2 = t1; // 대입

}

