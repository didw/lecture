// 17_delete_function- 227 page

class Singleton
{
public:
	Singleton()  = default; // ����Ʈ ������ ����� �޶�
	Singleton(const Singleton& s) = delete; // ���� �����ڸ� ���� �޶�
};

int main()
{
	Singleton s1;
	Singleton s2 = s1; 
}