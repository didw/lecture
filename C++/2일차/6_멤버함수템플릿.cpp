// 6_멤버함수템플릿 - 82 page 중요 합니다.

#include <iostream>
using namespace std;

// 1. complex를 템플릿으로 만드는 이유.
//    double이면 될거 같지만.. double은 느립니다.

// 2. T a = T();   T가 표준타입이거나 포인터 이면 0으로
//                     사용자 타입이면 디폴트 생성자로 초기화
//    zero initalize 라는 문법.


template<typename T> class complex
{
	T re, im;
public:
	complex(T r = T(), T i = T()) : re(r), im(i) {}

	// 일반화된 복사 생성자(generic 복사 생성자) - 82page아래 부분
	
	// "U가 T로 복사 될수 있다면 complex<U>도 complex<T>로 복사 될수 있어야 한다."

	template<typename U> complex(const complex<U>& c);

	// 모든 complex 끼리는 친구 이어야 한다.
	template<typename> friend class complex;
};

template<typename T> template<typename U> 
complex<T>::complex(const complex<U>& c)
{
	re = c.re;
	im = c.im;
}




int main()
{
	complex<int> c1(1, 2);
	complex<int>    c2 = c1;  // 복사 생성자. ok..
	complex<double> c3 = c1;  // ??
	c3 = c1;

	Animal* p = new Dog; // ok..

	shared_ptr<Dog> p1(new Dog);
	shared_ptr<Animal> p2 = p1; // ??되야 한다.
}





