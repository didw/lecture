#include <iostream>
using namespace std;

/*
// ���� : �Լ��� ���ڰ� 3����� �����ϰ�.. 1��° ������ Ÿ���� ����
//        ��Ÿ �Լ��� ����� ������

FirstArgumentType<T>::type n;

// ���� ���� - ���ڰ� 3����� ����
ArgumentType<T, 2>::type n;


// ���� ���� : ������ ������ 0~N ���϶�.. �����ֿ� ���ϴ�.
*/


// ���ڰ� 1���� �Լ��� �����մϴ�.

int f1(double d) { return 0; }


template<typename T> struct ResultType
{
	typedef T type;
};

template<typename R, typename A> struct ResultType<R(A)>
{
	typedef R type;
};

template<typename T> void foo(const T& a)  // ���� �Լ� Ÿ�� : int(double) 
{
	typename ResultType<T>::type n;

	cout << typeid(n).name() << endl;
}
int main()
{
	foo(f1);
}
