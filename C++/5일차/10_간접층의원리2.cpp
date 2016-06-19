// strcpy 에러 나오면 제일 위에 아래 한줄넣으세요.
#define _CRT_SECURE_NO_WARINGING
#include <iostream>
using namespace std;


// 참조계수 기반 string 클래스를 생각해 봅시다.
class String
{
	char* buf;
	int* ref;
public:
	String(const char* s)
	{
		buf = new char[strlen(s) + 1];
		strcpy(buf, s);
		ref = new int(1);
	}

	// [] 연산자 :객체를 배열 처럼 사용가능하게 한다.
	/*
	char& operator[](int index)
	{
		cout << "operator []" << endl;
		return buf[index];
	}
	*/

	// char의 대행자(Proxy)를 만든다.
	class CharProxy
	{
		String& s;
		int   idx;
	public:
		CharProxy(String& ss, int i) : s(ss), idx(i) {}

		// [] 가 우변에 있으면 CharProxy = > char 변환이 호출된다.
		operator char()
		{
			cout << "읽기하는 중. 자원 계속 공유" << endl;
			return s.buf[idx];
		}
		// [] 가 좌변에 있으면 대입연산자가 호출된다.
		CharProxy operator=(const char c)
		{
			cout << "쓰기하는중.. 자원 분할해야 한다." << endl;

			// s.buf를 분리하고 넣는다.
			s.buf[idx] = c;

			return *this;
		}
	};


	CharProxy operator[](int index)
	{
		cout << "operator []" << endl;
		return CharProxy(*this, index);
	}
};


int main()
{
	String s1 = "hello";
	String s2 = s1;     // 문자열은 공유 되고 있다.

	char c = s1[0]; // 'h' 공유 자원을 읽고 있다. 자원을 계속 공유해야 한다

//	cout << c << endl;

	s1[0] = 'x';     // 공유 자원을 분리하고 써야 한다.

//	cout << s1 << endl;
//	cout << s2 << endl;
}