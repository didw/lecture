
// �Ϲ� �Լ��� ����� �ֽ��ϴ�.
// �Լ��� �������� ������ : ���ڰ� �Ͻ��� ����ȯ �Ǿ �ٸ� �Լ��� ȣ�Ⱑ��
//       �����ϴ� ��     : �Ͻ��� ����ȯ �Ǳ� ���� ���� �Ǿ��ٴ� ���� �˱� ������
//							������ ����.
void foo(int a) {}
//void foo(double) = delete;

template<typename T> void goo(T a) {}
void goo(double) = delete;

int main()
{
	foo(3);
	foo(3.4);
}