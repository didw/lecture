// 1_����Ʈ������9 - 1��������..this_call4��

#include <iostream>
#include <windows.h> 
#include <conio.h> 
#include <memory>
using namespace std;

class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);
		self->Main(); 
		return 0;
	}
	virtual void Main() {}
};

class MyThread : public Thread
{
	int data;
public:
	virtual void Main() 
	{ 
		cout << "MyThread Main" << endl; 
		Sleep(5000);
		cout << "������ ����" << endl;
		data = 10;
	}
};

int main()
{
	{
		shared_ptr<MyThread> p(new MyThread);
		p->run();
	}

//	MyThread t;
//	t.run(); // ������ ������ Main �����Լ� ����..
	_getch();
}






