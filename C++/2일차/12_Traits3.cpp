// 12_traits
#include <iostream>
using namespace std;



//int  a;
//int* p; // p의 타입 : int*
//int x[5]; // 변수이름 : x   x의 타입 : int[5]
		// T[N]




template<typename T> struct IsArray    
{
	static constexpr int size = -1; // 배열이 아닌경우
	static constexpr bool value = false;
};
template<typename T, int N> struct IsArray<T[N]>  
{
	static constexpr int size = N ;
	static constexpr bool value = true;
};

template<typename T> void foo(const T& a)
{
	if (IsArray<T>::value)					// 위의 IsPointer를 수정해서

		cout << "배열 입니다. 크기는 " << IsArray<T>::size  << endl;		// IsArray 만들어 보세요
	else              
		cout << "배열이 아닙니다" << endl;
}

int main()
{
	int x[5];
	foo(x);
}





