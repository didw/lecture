// 3_���ø��⺻ - 75 page

//int    square(int a)    { return a * a; }
//double square(double a) { return a * a; }

// ������ �ڵ尡 �ݺ��Ǹ� �ڵ� �����⸦ �������.

// 1. ��ũ�θ� ����� �ڵ� ����
//   ���� : ��ó����� Ÿ���� �𸥴�. � Ÿ���� �Լ��� �ʿ�����
//          ����ϱ� ���� �� �ڵ�� ǥ���ؾ� �Ѵ�( MAKE_SQUARE(int))
/*
#define MAKE_SQUARE(T) T square(T a) { return a * a;}

MAKE_SQUARE(int)
MAKE_SQUARE(double)
*/

// 2. �����Ϸ��� ���� �ڵ� ���� - �����Ϸ��� �ڵ带 �м��ؼ� � Ÿ���� �ʿ�����
//							�˾� ���� �ִ�.

// Code Bloat : ���ø� ���� �����Ϸ��� �ʹ� ���� �Լ�(Ŭ����)�� ����
//				�ڵ� �޸� ��뷮�� �����ϴ� ����

// �ν��Ͻ�ȭ : ���ø��� Ÿ���� �����Ǿ ��¥ �Լ��� �Ǵ� ����
// �Ͻ��� �ν��Ͻ�ȭ : T�� �����Ϸ��� ���� 
// ����� �ν��Ͻ�ȭ : T�� ����ڰ� ����
template<typename T> T square(T a) { return a * a;}

int main()
{
	// �Լ� �ּ� ���
	cout << &square << endl; // error. square�� Ʋ(template)���� �Լ��� �ƴϴ�
	cout << &square<int> << endl; // ok.. ���� ������ printf("%p", &square<int>)

	square(3);
	square(3.3);
	short s = 3;
	//square(s); // square(int) ��� ? square(short)���� ?

	square<int>(s);
}




