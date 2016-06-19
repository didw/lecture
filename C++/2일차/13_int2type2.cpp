// 13_int2type
#include <iostream>
#include <type_traits>
using namespace std;



// �������� ���� �����Ͱ� �ƴ� ��츦 ���� �Լ� ���ø����� �����

// T�� �������϶��� ���Ǿ�� �Ѵ�. ��, C++ �Լ��� ����������Ѵ�.
template<typename T> void printv_pointer(T a)
{
	cout << a << " : " << *a << endl;
}
template<typename T> void printv_not_pointer(T a)
{
	cout << a << endl;
}
template<typename T> void printv(T a)
{
	// if ���� ����ð� ���繮�Դϴ�.
	// �׷��� �����Ͻÿ��� pointer ������ not_pointer ������ �Լ��� 
	// ��� �ʿ��ϴٰ� �����Ϸ��� �����ϰ� �˴ϴ�
	// �׷��� 2�� ������ ��� C++�Լ��� �����˴ϴ�.
	if (is_pointer<T>::value)  // if ( false )
		printv_pointer(a);
	else
		printv_not_pointer(a);
}




int main()
{
	int n = 10;

	printv(n);  

}



