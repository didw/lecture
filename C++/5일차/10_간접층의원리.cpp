// 10_�������ǿ���

// �ƹ��� ����� ������ ������(������)�� ����� �ذ��Ҽ� �ִ�.

// Vector�� ũ��� int ��� �����ڸ� �������
struct VectorSize
{
	int size;
	VectorSize(int n) : size(n) {} // int => VectorSize �Ͻ��� ����ȯ ����.
};

class Vector
{
public:
	Vector(VectorSize vs) // VectorSize => Vector �Ͻ��� ����ȯ ����.
	{
		int n = vs.size;
	}
//	Vector(int n) {}
};

void foo(Vector v) {}

int main()
{
	Vector v(10); //ok..
	foo(v); // ok
	foo(10); // 10(int) => Vector �� �Ͻ��� ����ȯ
}



