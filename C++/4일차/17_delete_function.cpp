// 17_delete_function- 227 page

class Singleton
{
public:
	Singleton()  = default; // 디폴트 생성자 만들어 달라
	Singleton(const Singleton& s) = delete; // 복사 생성자를 지워 달라
};

int main()
{
	Singleton s1;
	Singleton s2 = s1; 
}