#include <vector>
#include <list>
#include <string>
#include <algorithm>  
#include <iostream>
using namespace std;

/*
// STL�� �ݺ����� 5���� �з��� Ÿ��ȭ �մϴ�.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag       : input_iterator_tag  {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

// empty class(struct) : �Լ� �����ε��̳� ���ø� ���ڷ� ���..

// ��� �ݺ��ڸ� ���鶧 �ڽ��� ������ �ܺο� �˷��ݴϴ�.
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

// �ݺ����� ����
// 1. ��ü�� �� �ݺ���
// 2. ��¥ ������
/*
// �� 2���� �������� �ذ��ϴ� ����
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
void xadvance(T& p, int n)  // n > 0 �ΰ�츸 ����
{
	// �ݺ����� ������ ���� �Լ� ����
	//xadvance_imp(p, n, typename T::iterator_category() );
	xadvance_imp(p, n, typename iterator_traits<T>::iterator_category());
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	auto p = v.begin();
	xadvance(p, 5); // p�� 5ĭ �����ϴ� �Լ�
	cout << *p << endl;

	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* p1 = x;
	xadvance(p1, 5); // ??
}









