// 6_STL알고리즘
#include <iostream>
using namespace std;



// Step 3. 검색 대상 타입의 일반화 

template<typename T> 
T* xfind(T* first, T* last, T value)
{
	while (first != last && *first != value)
		++first;
	return first == last ? 0 : first;
}

int main()
{
	double x[10] = { 1,2,3,4,5,6,7,8,9,10 };

	double* p = xfind(x, x + 10, 5.0);

	if (p == 0)
		cout << "찾을수 없습니다." << endl;
	else
		cout << *p << endl;
}

