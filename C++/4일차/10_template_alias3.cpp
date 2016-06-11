// 10_template_alias3
#include <iostream>
#include <set>
#include <functional>
using namespace std;

// STL 사용시 코드가 복잡하면 typedef가 좋습니다.
//typedef set<int, greater<int>> SET;
//typedef set<double, greater<double>> SET_DOUBLE;

// 아래 처럼 할수 없을까 ? - typedef는 C문법이므로 template사용안됨.
//template<typename T> typedef set<T, greater<T>> SET;

// using 은 템플릿이 됩니다.
// "template alias" 또는 "template typedef" 라고 불리는 문법
template<typename T> using SET = set<T, greater<T>>;


int main()
{
//	set<int> s;  // 내부적으로 들어오는 data를 비교 하기 위해 less<>사용
	//set<int, greater<int>> s; // greater 함수객체를 사용해서 비교

	SET<int> s;
	// greater를 사용해서 비교하는 double 타입의 set 필요
	//set<double, greater<double>> s2;
	SET<double> s2;
	s.insert(10);
	s.insert(20);

	SET<int>::iterator p = s.begin();

//	set<int, greater<int>>::iterator p = s.begin();
}






