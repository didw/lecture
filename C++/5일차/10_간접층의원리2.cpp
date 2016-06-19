// strcpy ���� ������ ���� ���� �Ʒ� ���ٳ�������.
#define _CRT_SECURE_NO_WARINGING
#include <iostream>
using namespace std;


// ������� ��� string Ŭ������ ������ ���ô�.
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

	// [] ������ :��ü�� �迭 ó�� ��밡���ϰ� �Ѵ�.
	/*
	char& operator[](int index)
	{
		cout << "operator []" << endl;
		return buf[index];
	}
	*/

	// char�� ������(Proxy)�� �����.
	class CharProxy
	{
		String& s;
		int   idx;
	public:
		CharProxy(String& ss, int i) : s(ss), idx(i) {}

		// [] �� �캯�� ������ CharProxy = > char ��ȯ�� ȣ��ȴ�.
		operator char()
		{
			cout << "�б��ϴ� ��. �ڿ� ��� ����" << endl;
			return s.buf[idx];
		}
		// [] �� �º��� ������ ���Կ����ڰ� ȣ��ȴ�.
		CharProxy operator=(const char c)
		{
			cout << "�����ϴ���.. �ڿ� �����ؾ� �Ѵ�." << endl;

			// s.buf�� �и��ϰ� �ִ´�.
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
	String s2 = s1;     // ���ڿ��� ���� �ǰ� �ִ�.

	char c = s1[0]; // 'h' ���� �ڿ��� �а� �ִ�. �ڿ��� ��� �����ؾ� �Ѵ�

//	cout << c << endl;

	s1[0] = 'x';     // ���� �ڿ��� �и��ϰ� ��� �Ѵ�.

//	cout << s1 << endl;
//	cout << s2 << endl;
}