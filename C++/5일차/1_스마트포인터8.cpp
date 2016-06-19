#include <iostream>
#include <memory>
#include <type_traits>
using namespace std;

class Car
{
public:
	~Car() { cout << "Car �ı�" << endl; }
};

int main()
{
	weak_ptr<Car> w1;
	{
		shared_ptr<Car> s1(new Car);

		w1 = s1;

	} // s1�� �ı��Ǿ Car�� �ı� �ȴ�. ������ ���� w1�� �ı����� �ʾҴ�

	// w1�� ����ص� �ɱ� ?
	// �Ʒ� ó�� �ص� �ȵ˴ϴ�. ��Ƽ������ ȯ���̰� �ٸ� �����尡 shared_ptr<>
	// �� ������ ������ ������ �˴ϴ�.
	// �׷��� weak_ptr�� -> �����ڰ� ������ �Ǿ� ���� �ʽ��ϴ�.
	// ��, weak_ptr<>�δ� Car�� �����Ҽ� �����ϴ�.

	//if ( !w1.expired() )
	//	w1->Go();
	
	// weak_ptr�� ���� ��ü�� �����Ϸ��� shared_ptr<>�� �ٽ� ������ �մϴ�.
	shared_ptr<Car> p3 = w1.lock();

	if (p3)
	{
		// p3���
	}
	else
	{
		cout << "��ü �ı�" << endl;
	}

	// w1���� ��ü�� �ı� ���θ� �����Ҽ� �� ����.
	if (w1.expired())
		cout << "��ü �ı���" << endl;

}









