// 1_����Ʈ������9 - 1��������..this_call4��

#include <iostream>
#include <windows.h> 
#include <conio.h> 
#include <memory>
using namespace std;

// �ܺο��� shared_ptr<>�� ������� ������
// Ŭ���� ��� �Լ����� this �� ����ؼ� ��������� ���� �ϰ� �ϴ� ���.

// �ٽ� : Thread ��� C++ ��ü�� ������ ���� �������� ����� ���Ͻ� �ϴ� ���

class Thread : public enable_shared_from_this<Thread>
{
	shared_ptr<Thread> self; // �ڽ��� ��������� �����ϱ� ����.
public:
	//Thread() { self = this; }  // bug.. �����尡 ��������� ���������
								// �����ؾ� �մϴ�.


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

		// �����尡 ���� �ɶ� ������� ����
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
		cout << "������ ����" << endl;
		data = 10;
	}
};

int main()
{
	{
		shared_ptr<MyThread> p(new MyThread);
		p->run();

	}	// �̼��� p�� �ı� ������ MyThread ��ü�� ������ ������ ����ñ���
		// ����Ǿ�� �մϴ�.

	_getch();
}





/*
int main()
{
	int* p = new int;
	shared_ptr<int> p1( p );
	shared_ptr<int> p2 = p1; // ok.. ��������� 2�� �˴ϴ�.


	int* pp = new int;
	shared_ptr<int> p3(pp);
	shared_ptr<int> p4 = p3; //p3�� p4�� ���� �������

	shared_ptr<int> p5(pp); // ?? ��������� 2�� �ɱ�� ?
	shared_ptr<int> p6 = p5;// p5�� p6�� ���� ���� ���



	
}
*/