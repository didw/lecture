// 9_���ø��κ�����ȭ - ������ �ٽ�!!

#include <iostream>
using namespace std;

// 89 page

// "Primary template"
template<typename T> class stack
{
public:
	void push(T a) { cout << "T" << endl; }
};

// "partial specialization"(�κ� ����ȭ)
template<typename T> class stack<T*>
{
public:
	void push(T a) { cout << "T*" << endl; }
};

// "specialization(����ȭ, Ư��ȭ)"
template<> class stack<char*>
{
public:
	void push(char* a) { cout << "char*" << endl; }
};

int main()
{
	stack<int>   s1; s1.push(0);
	stack<int*>  s2; s2.push(0);
	stack<char*> s3; s3.push(0);
}





