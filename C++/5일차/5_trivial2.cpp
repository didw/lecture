#include <iostream>
#include <type_traits>
using namespace std;

// ��� Ÿ���� �迭�� �����ϴ� �Լ�
template<typename T> void copy_type(T* dst, T* src, int sz)
{
	if (is_trivially_copyable<T>::value)
	{
		cout << "��������ڰ� �ϴ����� ���� ���" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "���� �����ڰ� �ϴ� ���� �ִ� ���" << endl;

		while (sz--)
		{
			new(dst) T(*src); // ��������� ȣ�� (placement new)
			++dst, ++src;
		}
	}
}


int main()
{
	char s1[10] = "hello";
	char s2[10];

	//strcpy(s2, s1); // generic �ұ� ?

	copy_type(s2, s1, 10); 
}