// 10_���ø�����
// 1. type����.
// 2. ������ ��� ����(�Ǽ� �ȵ�, ���� �ȵ�)

template<typename T = int, int N = 10> class stack
{
	T buf[N];
};

int main()
{
	stack<int> s3; // N�� 10

	stack<> s4; // ��� ���ڸ� ����Ʈ��!

	stack<int, 10> s1;

	int a = 10;
	stack<int, a> s2; // error
}


