// 3_const4

// C++11�� constexpr �Լ� : �Լ� ���ڷ� literal �� ���޵Ǹ�
//						������ �ð��� �Լ��� ������ ������ �ش�.
constexpr int Add(int a, int b)
{
	return a + b;
}

int main()
{
	int x[ Add(1, 2) ]; // ??
	
	int a = 1, b = 2;
	Add(a, b);
}


