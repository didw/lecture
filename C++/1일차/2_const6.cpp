


// 상수 함수는 선택이 아닌 필수 입니다.
// 객체의 상태(멤버 data)를 변경하지 않은 모든 함수들(getXXXX) 은 반드시
// 상수함수가 되어야 합니다.

class Rect
{
	int x, y, w, h;
public:
	int getArea() const { return w *h; }
};

void foo(const Rect& r)
{
	int n = r.getArea(); // ?
}

int main()
{
	Rect r; // 초기화 했다고 가정하고
	int n = r.getArea();
	foo(r);
}



