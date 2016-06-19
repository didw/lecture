#include <iostream>
#include <type_traits>
using namespace std;

// 모든 타입의 배열을 복사하는 함수
template<typename T> void copy_type(T* dst, T* src, int sz)
{
	if (is_trivially_copyable<T>::value)
	{
		cout << "복사생성자가 하는일이 없는 경우" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "복사 생성자가 하는 일이 있는 경우" << endl;

		while (sz--)
		{
			new(dst) T(*src); // 복사생성자 호출 (placement new)
			++dst, ++src;
		}
	}
}


int main()
{
	char s1[10] = "hello";
	char s2[10];

	//strcpy(s2, s1); // generic 할까 ?

	copy_type(s2, s1, 10); 
}