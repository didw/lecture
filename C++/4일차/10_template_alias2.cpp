// 10_template_alias2

// C++11 typedef 대신 using 사용
using DWORD = int;			// typedef int DWORD; 와 동일
using PFUNC = void(*)(int);

int main()
{
	DWORD n;
	PFUNC f;
}