// 12_traits
#include <iostream>
using namespace std;

// Traits : ���ø� ����T�� ���� �پ��� ������ ��� ����.
//          ������ �ð��� ���Ǵ� �Լ� => ��Ÿ �Լ���� �մϴ�.

// ����� ��
// 1. ����ü ���ø����� ����ϴ�.
// 2. primary template �������� false ���� ( value = false��� �ǹ�)
// 3. �κ� ����ȭ ����           true ���� ( value = true ��� �ǹ�)

/*
struct People
{
	int age = 0;
	bool value = false; // error.
	enum { value = false }; // ok..
	static const bool value = false; // 2000�� �Ĺݿ� �̹��� ���.
}
*/

template<typename T> struct IsPointer
{
	//enum { value = false }; // ���� ��Ÿ��
	static constexpr bool value = false; // C++11 ��Ÿ��
};

template<typename T> struct IsPointer<T*>
{
	enum { value = true };
};


template<typename T> void foo(const T& a)
{	
	if ( IsPointer<T>::value )  cout << "������ �Դϴ�." << endl;
	else                 	  cout << "�����Ͱ� �ƴմϴ�" << endl;
}

int main()
{
	int n = 0;
	foo(&n);
}





