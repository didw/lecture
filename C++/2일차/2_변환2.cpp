#include <iostream>
using namespace std;

// 변환의 장단점.. - 53 page 2번

// 생성자와 소멸자에서 자원 관리를 하면 편리하다. 
// RAII : Resurce Acquision Is Initialize 라는개념
class OFile
{
	FILE* file;
public:
	// explicit 생성자 : 인자가 한개인 생성자가 암시적 변환을 일으키는 것을 막는다
	//					단, 명시적 변환은 허용
	explicit OFile(const char* name, const char* mode = "wt")
	{
		file = fopen(name, mode);
	}
	~OFile() { fclose(file); }

	// OFile => FILE* 로의 변환을 허용한다.
	// C++11 부터는 변환연산자도 explicit 를 붙일수 있다.
	explicit operator FILE*() { return file; }
};


void foo(OFile f) {}

int main()
{
	OFile f("a.txt");

	foo(f); // ok.. 당연하다!!

	foo("hello"); // 잘못된 코드.. 하지만 컴파일 에러가 나지 않는다 ???
				// const char* => OFile 암시적 변환 되고 있다.
}







/*
int main()
{
	OFile f("a.txt");

	fprintf(f, "hello"); // ?
	fputs("world", f);   // ?


	String s1 = "hello";
	char buf[10];

	strcpy(buf, s1); // 되는것이 좋을까요? 안되는게 좋을까요 ?
					// String => const char* 로의 암시적 변환 필요


//	FILE* f = fopen("a.txt", "wt");
//	fclose(f);
}
*/





