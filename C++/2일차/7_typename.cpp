// 7_typename
class AAA
{
public:
	//......
	//static int DWORD;
	typedef int DWORD;
};
int p = 0;

template<typename T> typename T::DWORD foo(T a)
{
	typename T::DWORD * p; // �� �ڵ带 �ؼ��� ������
				// 1. DWORD�� static ��� ����Ÿ �ε� ���ϱ� p
				// 2. DWORD�� T�� ������ Ÿ��(typedef��)�̴�.
				//    ������ ���� p�� �����ϰ� �ִ�.

	return 0;
}
int main()
{
	AAA aaa;
	foo(aaa);
}
// 85page

