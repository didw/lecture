// 12_traits
#include <iostream>
using namespace std;



//int  a;
//int* p; // p�� Ÿ�� : int*
//int x[5]; // �����̸� : x   x�� Ÿ�� : int[5]
		// T[N]




template<typename T> struct IsArray    
{
	static constexpr int size = -1; // �迭�� �ƴѰ��
	static constexpr bool value = false;
};
template<typename T, int N> struct IsArray<T[N]>  
{
	static constexpr int size = N ;
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	if (IsArray<T>::value)					// ���� IsPointer�� �����ؼ�

		cout << "�迭 �Դϴ�. ũ��� " << IsArray<T>::size  << endl;		// IsArray ����� ������
	else              
		cout << "�迭�� �ƴմϴ�" << endl;
}

int main()
{
	int x[5];
	foo(x);
}





