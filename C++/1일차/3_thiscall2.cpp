// 3_thiscall2


// 15page
// 1. 일반 함수 포인터에 멤버 함수의 주소를 담을수 없다.
// 2. 일반 함수 포인터에 static 멤버 함수의 주소를 담을수 있다. 
// 3. 멤버함수 포인터를 만들고 사용하는 방법
//    - 아래 main 참고, 교재 15 page 참고.

class Dialog
{
public:
	void Close() {}
};

void foo() {}

int main()
{
	void(*f1)() = &foo; // ok
	//void(*f2)() = &Dialog::Close; // 될까요 ??

	// 멤버 함수 포인터 만드는 법

	void(Dialog::*f2)() = &Dialog::Close; // 

	//f2(); // 될까요 ? error. this가 없다.

	Dialog dlg;
	(dlg.*f2)();  // 결국 dlg.Close()입니다...

}






