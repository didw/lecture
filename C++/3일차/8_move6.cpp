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
// move�� copy�� ���ÿ� �����ϴ� Ŭ���� �����
class Object
{
	Test data;
public:
	/*
	void set(Test t)  // call by value ���  const &�� �������.
	{
		data = t;
	}
	*/
	// ��� 1. copy�� move�� �����ϱ� ���� �Լ��� 2�� ������.
	void set(const Test& t) {	data = t;	}
	void set(Test&& t)   	{	data = move(t);	}

	// ��� 2. call by value       "C++11 pass by value" ��� �˻��� ������
	void set2(Test t) { data = move(t); }

	// ����
	// move�� ���� ������ call by value�� ������ 
	// ���� ������, ���ڸ� data�� ������ ���� ���� �����ڸ� ȣ���ϹǷ� 
	// 2ȸ�� ���� ������ ȣ���� �ȴ�.. ������尡 ũ��
	// void set2(Test t) { data = t; }
};
int main()
{
	Object obj;

	Test t;
	obj.set(t); // ����� ���ڸ� ������ �޶�.    ���� �����ڸ� 1ȸ
	obj.set(move(t)); // move�� ���� ����       move 1ȸ

	obj.set2(t);      //   ���� 1ȸ move 1ȸ.
	obj.set2(move(t));//   move 2ȸ
}




