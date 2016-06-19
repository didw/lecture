// 3_thiscall3 - 16 page
#include <iostream>
#include <windows.h> // win32 api
#include <conio.h> 
using namespace std;

// 멀티 스레드 개념을 객체지향으로 설계해 봅시다.
// 아래 클래스가 라이브러리 설계자가 만든 클래스
class Thread
{
public:
	void run() { CreateThread(0, 0, threadMain, this, 0, 0); }

	// 1. 아래함수가 static 멤버 일수 밖에 없는 이유를 알아야 합니다
	// 2. 아래 함수에서 this를 사용하게 하기 위해 인자로 전달하는 기법.
	static DWORD __stdcall threadMain(void* p)
	{
		Thread* self = static_cast<Thread*>(p);

		self->Main(); // Main(self)


		//Main(); // 가상함수 호출
				// this->Main() 이 되고 다시 Main(this) 로 호출되어야 합니다.

		return 0;
	}
	virtual void Main() {} // void Main(Thread* const this)
}; 

// cafe.naver.com/cppmaster


// 빌드하면 run()함수에서 에러가 발생합니다. 왜 ?? 에러 일까요?



// 아래 클래스가 라이브러리 사용자 클래스 입니다.
class MyThread : public Thread
{
public:
	virtual void Main() { cout << "MyThread Main" << endl; }
};
int main()
{
	MyThread t;
	t.run(); // 이순간 스레드가 생성되어서 Main() 가상함수가 수행되어야 합니다.
	_getch();
}






