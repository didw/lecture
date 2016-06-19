#include <iostream>
#include <vector>           
#include <range/v3/all.hpp> 
using namespace std;
using namespace ranges;

// 어제 세미나 코드중 range 코드에 에러가 있어서 실행되는 버전으로 다시 보내 드립니다. 주석 참고 하세요
// 빌드 해보시려면..

// ubuntu 환경에서 git 설치후
// git clone https://github.com/ericniebler/range-v3

// 해서 range-v3 소스를 얻은후에.

// /home/userid/range-v3에 소스를 다운했다면

// g++ sample1.cpp -std=c++14 -I/home/userid/range-v3  으로 컴파일 하면 실행해 볼수 있습니다.

int main()
{
	vector<int> v1{1,2,3,4,5,6,7,8,9,10};

	// vector를 가지고 ranges를 만들어 냅니다.
	auto r1 = v1 | view::take(9);     

	cout << r1 << endl;

	// ranges는 컨테이너가 아니라 iterator's pair 입니다
	// 즉 range를 사용해서 값을 변경하면 원본이 변경됩니다.
	
	RANGES_FOR( int& n, r1)
	{
		n = 0;
	}
	for( int a : v1)
		cout << a << endl;
}

