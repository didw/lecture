// 7_����12

int main()
{
	int(*f)(int, int);

	{
		int v1 = 10;

		f = [&v1](int, int) { return v1; }; // error �� ������ 2������ �ڼ��� ����帳�ϴ�.
	}

	f(1,2); // �������� �� ������ ������.
	/*
	int* p = new int[10];
	delete[] p; // ������ ����(Undefined) �߻�.
				// p�� int* �̴�.

	int* p1 = new int;
	delete p1; // p1�� int*��� ����� �ȴ�. 4����Ʈ ����
	*/
}