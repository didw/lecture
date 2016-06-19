// 8_value_type
#include <vector>
#include <list>
#include <iostream>
using namespace std;

/*
void print(vector<int>& v)
{
	int n = v.front();

	cout << n << endl;
}
*/
/*
template<typename T> void print(vector<T>& v)
{
	T n = v.front();

	cout << n << endl;
}
*/

template<typename T> void print(T& v)
{
	// T               => list<double> 
	// T::value_type   => double

	// C++98/03 시절
	//typename T::value_type n = v.front();


	// C++11 도입. - 87 page
	auto n = v.front();

	cout << n << endl;
}



int main()
{
	list<double> v(10, 3); // 10개를 3으로

	print(v);
}

// 템플릿 기반의 모든 컨테이너는 자신이 저장하는 타입이 있다.
// 외부에서 그 타입을 알고 싶을때가 있다. - 위의 print()
/*
// 그래서 아래처럼 만들어야 한다.
template<typename T> class list
{
public:
	typedef T value_type;  // 핵심!!!
	//.....
};

list<int> s(10, 3);

list<int>::value_type n = s.front(); // n은 결국 int 입니다.
*/





