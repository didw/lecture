// 1_new5
#include <iostream>
#include <vector>
using namespace std;


// STL의 vector를 생각해 봅시다.
int main()
{
	vector<int> v(10, 0); // 10개를 0으로 초기화

	v.resize(7); // 이 순간의 알고리즘을 생각해봅시다.

	cout << v.size()     << endl; // 7
	cout << v.capacity() << endl; // 10

	v.push_back(0); // 끝에 하나 추가

	cout << v.size() << endl;     // 8
	cout << v.capacity() << endl; // 10

	v.shrink_to_fit(); // 필요없는 메모리 삭제해달라

	cout << v.size() << endl;     // 8
	cout << v.capacity() << endl; // 8

	//-----------------------
	// DBConnect 객체는 생성자에서 DB에 접속한다고 가정합니다.

	vector<DBConnect> v2(10); 

	v2.resize(7); // 줄어든 3개의 객체는 메모리에 계속 있습니다.
				  // 하지만 소멸자를 호출해서 DB를 닫아야 합니다.
				  // 소멸자의 명시적 호출이 필요하게 됩니다.

	v2.resize(8); // 늘어난 한개의 객체를 위한 메모리 공간은 이미 있습니다.
				  // 하지만 생성자를 호출해서 DB에 다시 접속해야 합니다.
				  // 생성자의 명시적 호출이 필요합니다.
}




