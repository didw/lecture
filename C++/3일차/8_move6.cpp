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

//------------------
// move와 copy를 동시에 지원하는 클래스 만들기
class Object
{
	Test data;
public:
	/*
	void set(Test t)  // call by value 대신  const &를 사용하자.
	{
		data = t;
	}
	*/
	// 방법 1. copy와 move를 지원하기 위해 함수를 2개 만들자.
	void set(const Test& t) {	data = t;	}
	void set(Test&& t)   	{	data = move(t);	}

	// 방법 2. call by value       "C++11 pass by value" 라고 검색해 보세요
	void set2(Test t) { data = move(t); }

	// 참고
	// move가 없던 시절은 call by value로 받으면 
	// 인자 받을때, 인자를 data에 넣을때 각각 복사 생성자를 호출하므로 
	// 2회의 복사 생성자 호출이 된다.. 오버헤드가 크다
	// void set2(Test t) { data = t; }
};
int main()
{
	Object obj;

	Test t;
	obj.set(t); // 복사로 인자를 전달해 달라.    복사 생성자만 1회
	obj.set(move(t)); // move로 인자 전달       move 1회

	obj.set2(t);      //   복사 1회 move 1회.
	obj.set2(move(t));//   move 2회
}




