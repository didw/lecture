// 1_스마트포인터9 - 1일차에서..this_call4번

#include <iostream>
#include <windows.h> 
#include <conio.h> 
#include <memory>
using namespace std;

// 외부에서 shared_ptr<>이 만들어져 있을때
// 클래스 멤버 함수에서 this 를 사용해서 참조계수를 공유 하게 하는 기술.

// 핵심 : Thread 라는 C++ 객체의 수명을 실제 스레드의 수명과 동일시 하는 기술

class Thread : public enable_shared_from_this<Thread>
{
	shared_ptr<Thread> self; // 자신의 참조계수를 증가하기 위해.
public:
	//Thread() { self = this; }  // bug.. 스레드가 만들어지면 참조계수가
								// 증가해야 합니다.


	void run() 
	{ 
		//self = this;
		self = shared_from_this();

		CreateThread(0, 0, threadMain, this, 0, 0);
	}

	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);
		self->Main();

		// 스레드가 종료 될때 참조계수 감소
		self->self.reset();

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

	}	// 이순간 p는 파괴 되지만 MyThread 객체의 수명은 스레드 종료시까지
		// 연장되어야 합니다.

	_getch();
}





/*
int main()
{
	int* p = new int;
	shared_ptr<int> p1( p );
	shared_ptr<int> p2 = p1; // ok.. 참조계수가 2가 됩니다.


	int* pp = new int;
	shared_ptr<int> p3(pp);
	shared_ptr<int> p4 = p3; //p3과 p4는 동일 참조계수

	shared_ptr<int> p5(pp); // ?? 참조계수가 2가 될까요 ?
	shared_ptr<int> p6 = p5;// p5와 p6이 동일 참조 계수



	
}
*/