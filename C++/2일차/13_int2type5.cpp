#include <iostream>
using namespace std;


// 99 page
/*
template<typename T, T N> struct integral_constant
{
	static constexpr T value = N;
};

integral_constant<int,   0> n0;
integral_constant<short, 0> s0;


// true/false             : �� ������ ��Ÿ���� ��, ���� Ÿ��
// true_type / false_type : �� ������ ��Ÿ���� Ÿ��, �ٸ� Ÿ��
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

// is_pointer �����
// �ᱹ �θ��� false_type�ȿ� value = false�� �ֽ��ϴ�.
template<typename T> struct is_pointer     : false_type {};
template<typename T> struct is_pointer<T*> : true_type {};

*/

#include <type_traits> // �� �ȿ� ���� �ִ� �ڵ尡 �ֽ��ϴ�.

template<typename T> void printv_imp(T a, true_type )  { cout << a << " : " << *a << endl;}
template<typename T> void printv_imp(T a, false_type ) { cout << a << endl;}


template<typename T> void printv(T a)
{

	printv_imp(a, is_pointer<T>() );  // Ŭ�����̸�() :�ӽð�ü ����
									 //  Point(); // Point ��ü ����
}







int main()
{
	int n = 10;

	printv(n);

}


