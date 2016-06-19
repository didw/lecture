// 6_����Լ����ø� - 82 page �߿� �մϴ�.

#include <iostream>
using namespace std;

// 1. complex�� ���ø����� ����� ����.
//    double�̸� �ɰ� ������.. double�� �����ϴ�.

// 2. T a = T();   T�� ǥ��Ÿ���̰ų� ������ �̸� 0����
//                     ����� Ÿ���̸� ����Ʈ �����ڷ� �ʱ�ȭ
//    zero initalize ��� ����.


template<typename T> class complex
{
	T re, im;
public:
	complex(T r = T(), T i = T()) : re(r), im(i) {}

	// �Ϲ�ȭ�� ���� ������(generic ���� ������) - 82page�Ʒ� �κ�
	
	// "U�� T�� ���� �ɼ� �ִٸ� complex<U>�� complex<T>�� ���� �ɼ� �־�� �Ѵ�."

	template<typename U> complex(const complex<U>& c);

	// ��� complex ������ ģ�� �̾�� �Ѵ�.
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
	complex<int>    c2 = c1;  // ���� ������. ok..
	complex<double> c3 = c1;  // ??
	c3 = c1;

	Animal* p = new Dog; // ok..

	shared_ptr<Dog> p1(new Dog);
	shared_ptr<Animal> p2 = p1; // ??�Ǿ� �Ѵ�.
}





