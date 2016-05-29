#include <iostream>
using namespace std;

// ��ȯ�� �����.. - 53 page 2��

// �����ڿ� �Ҹ��ڿ��� �ڿ� ������ �ϸ� ���ϴ�. 
// RAII : Resurce Acquision Is Initialize ��°���
class OFile
{
	FILE* file;
public:
	// explicit ������ : ���ڰ� �Ѱ��� �����ڰ� �Ͻ��� ��ȯ�� ����Ű�� ���� ���´�
	//					��, ����� ��ȯ�� ���
	explicit OFile(const char* name, const char* mode = "wt")
	{
		file = fopen(name, mode);
	}
	~OFile() { fclose(file); }

	// OFile => FILE* ���� ��ȯ�� ����Ѵ�.
	// C++11 ���ʹ� ��ȯ�����ڵ� explicit �� ���ϼ� �ִ�.
	explicit operator FILE*() { return file; }
};


void foo(OFile f) {}

int main()
{
	OFile f("a.txt");

	foo(f); // ok.. �翬�ϴ�!!

	foo("hello"); // �߸��� �ڵ�.. ������ ������ ������ ���� �ʴ´� ???
				// const char* => OFile �Ͻ��� ��ȯ �ǰ� �ִ�.
}







/*
int main()
{
	OFile f("a.txt");

	fprintf(f, "hello"); // ?
	fputs("world", f);   // ?


	String s1 = "hello";
	char buf[10];

	strcpy(buf, s1); // �Ǵ°��� �������? �ȵǴ°� ������� ?
					// String => const char* ���� �Ͻ��� ��ȯ �ʿ�


//	FILE* f = fopen("a.txt", "wt");
//	fclose(f);
}
*/





