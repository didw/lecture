#include <vector>
#include <list>
#include <string>
#include <algorithm>  
#include <iostream>
using namespace std;

/*
// STL은 반복자의 5가지 분류를 타입화 합니다.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag       : input_iterator_tag  {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// empty class(struct) : 함수 오버로딩이나 템플릿 인자로 사용..

// 모든 반복자를 만들때 자신의 종류를 외부에 알려줍니다.
template<typename T> class slist_iterator
{
public:
	typedef  forward_iterator_tag    iterator_category;
};

template<typename T> class vector_iterator
{
public:
	typedef  random_access_iterator_tag    iterator_category;
};
*/


template<typename T> void xadvance_imp(T& p, int n, input_iterator_tag )
{
	while (n--) ++p;
}

template<typename T> void xadvance_imp(T& p, int n, random_access_iterator_tag )
{
	p = p + n;
}

// 반복자의 종류
// 1. 객체로 된 반복자
// 2. 진짜 포인터
/*
// 위 2개의 차이점을 해결하는 도구
template<typename T> struct iterator_traits
{
	typedef  typename T::iterator_category    iterator_category;
};

template<typename T> struct iterator_traits<T*>
{
	typedef random_access_iterator_tag   iterator_category;
};
*/

template<typename T>
void xadvance(T& p, int n)  // n > 0 인경우만 생각
{
	// 반복자의 종류에 따라 함수 선택
	//xadvance_imp(p, n, typename T::iterator_category() );
	xadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = v.begin();
	xadvance(p, 5); // p를 5칸 전진하는 함수
	cout << *p << endl;

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = x;
	xadvance(p1, 5); // ??
}









