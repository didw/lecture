// 1_스마트포인터9 - 1일차에서..this_call4번

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
		cout << "스레드 종료" << endl;
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
//	t.run(); // 스레드 생성후 Main 가상함수 실행..
	_getch();
}






