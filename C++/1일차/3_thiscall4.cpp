// 3_thiscall3 - 16 page
#include <iostream>
#include <windows.h> // win32 api
#include <conio.h> 
using namespace std;

// ��Ƽ ������ ������ ��ü�������� ������ ���ô�.
// �Ʒ� Ŭ������ ���̺귯�� �����ڰ� ���� Ŭ����
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 1. �Ʒ��Լ��� static ��� �ϼ� �ۿ� ���� ������ �˾ƾ� �մϴ�
	// 2. �Ʒ� �Լ����� this�� ����ϰ� �ϱ� ���� ���ڷ� �����ϴ� ���.
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		self->Main(); // Main(self)


		//Main(); // �����Լ� ȣ��
				// this->Main() �� �ǰ� �ٽ� Main(this) �� ȣ��Ǿ�� �մϴ�.

		return 0;
	}
	virtual void Main() {} // void Main(Thread* const this)
}; 

// cafe.naver.com/cppmaster


// �����ϸ� run()�Լ����� ������ �߻��մϴ�. �� ?? ���� �ϱ��?



// �Ʒ� Ŭ������ ���̺귯�� ����� Ŭ���� �Դϴ�.
class MyThread : public Thread
{
public:
	virtual void Main() { cout << "MyThread Main" << endl; }
};
int main()
{
	MyThread t;
	t.run(); // �̼��� �����尡 �����Ǿ Main() �����Լ��� ����Ǿ�� �մϴ�.
	_getch();
}






