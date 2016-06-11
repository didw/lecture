
enum class Shape { rect = 1, circle = 2 };

int main()
{
	Shape s = Shape::rect; // ok..
	//int n = Shape::rect; // error
	Shape s = 3; // C++14. 안됨..
				 // C++17. 허용하자는 제안서 제출됨.
}

// 핸들 : 대상체의 번호를 담는 data 타입..
//HWND : 윈도우 번호, HICON : 아이콘 번호

// 핸들만들기 1
typedef int HWND;
typedef int HICON;

// 서로 다른 타입을 가지는 핸들 만들기
struct __HWND {};
typedef struct __HWND *HWND;

struct __HICON {};
typedef struct __HICON *HICON;

// C++ 17 에서 이야기 되는 방식.
enum class HWND {};
enum class HICON {};

class HWND {};  HWND h = 10;

void MoveWindow(HWND h, int x, int y) {}

int main()
{
	HICON h = 0;
	MoveWindow(h, 100, 100);
}





