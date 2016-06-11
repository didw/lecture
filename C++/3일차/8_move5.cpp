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

// Big 5 : �Ҹ���, ���� ������, ���� ���Կ�����, move ������, move ���Կ�����

// ��Ģ 1. Big5�� �ϳ��� ������ ������ �����Ϸ��� ��� ����� �ش�.

//      2. RuleOf3 : �Ҹ���, ���� ������, ���Կ������� �ϳ��� �����ص�..
//				     ������ 2���� �����Ϸ� ����� �ش�. ��, ���������� ����
//                   move�� ���� ����. => ������ ��������ڸ� ����ؼ� move

//    3. move �迭 �Լ��� �����ϸ� ���� �迭 �Լ��� ���� ���� �ʴ´�.
//	     �ݵ�� ����ڰ� ������ �Ѵ�.

// ���..
// �ϳ��� Ŭ������ ���� �迭�� �����Ҽ��� �ִ�.
//	   ���� �����ڷ� move�� �ص� �ǹǷ�..

// move�迭 �Լ��� �����Ҽ��� ����.
//     move �����ڷ� ���縦 �Ҽ��� �����Ƿ�..

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

