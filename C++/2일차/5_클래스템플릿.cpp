// 5_Ŭ�������ø� - 79 page

template<typename T> class stack
{
	T buf[10];
public:
	// ������ �����ڷ� �´� ���� ?
	stack()    {} // 1 ok..
	stack<T>() {} // 2 �Ϻ� �����Ϸ��� ���.. ������ 1ó�� ����ؾ� �Ѵ�.

	// ���� �����ڷ� �´� ���� ?
	stack(const stack&    s) {} // 1. ���� ������ �ϰ�츸 ��ǥ�� ���.
	stack(const stack<T>& s) {} // 2. ok..

	// ��� �Լ��� �ܺ� ����
	void push(T a);

	// Ŭ���� ���ø��� ��� �Լ� ���ø�
	template<typename U> T foo(U a);
};


template<typename T> template<typename U> T stack<T>::foo(U a)
{

}





template<typename T> void stack<T>::push(T a) // 80 page ���� ���κ�
{

}


//template<typename T> void foo(stack& s)    {} // 1. error
//template<typename T> void foo(stack<T>& s) {} // 2. ok

int main()
{
	stack      s1; // error. stack �� Ÿ���� �ƴϴ�. Ʋ(template)�̴�.
	stack<int> s2; // ok.    stack<int> �� Ÿ���̴�.
}






