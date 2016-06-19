
enum class Shape { rect = 1, circle = 2 };

int main()
{
	Shape s = Shape::rect; // ok..
	//int n = Shape::rect; // error
	Shape s = 3; // C++14. �ȵ�..
				 // C++17. ������ڴ� ���ȼ� �����.
}

// �ڵ� : ���ü�� ��ȣ�� ��� data Ÿ��..
//HWND : ������ ��ȣ, HICON : ������ ��ȣ

// �ڵ鸸��� 1
typedef int HWND;
typedef int HICON;

// ���� �ٸ� Ÿ���� ������ �ڵ� �����
struct __HWND {};
typedef struct __HWND *HWND;

struct __HICON {};
typedef struct __HICON *HICON;

// C++ 17 ���� �̾߱� �Ǵ� ���.
enum class HWND {};
enum class HICON {};

class HWND {};  HWND h = 10;

void MoveWindow(HWND h, int x, int y) {}

int main()
{
	HICON h = 0;
	MoveWindow(h, 100, 100);
}





