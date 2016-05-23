// 3_thiscall - 13 page ~

class Point
{
	int x, y;
public:
	void set(int a, int b) // void set( Point* const this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;  // this->y = b; 라고 컴파일 됩니다.
	}

	static void foo(int a)// void foo(int a)
	{
		x = a;	// this->x = a; 로 변경해야 하는데 this가 없다. error
	}
};
int main()
{
	Point::foo(10);  // 객체 없이 호출

	Point p1, p2;
	p1.set(10, 20); // 이 한줄의 원리를 생각해 봅시다.
					// set(&p1, 10, 20)으로 변하게 됩니다.
					// push		20
					// push		10
					// mov      ecx, &p1  객체 주소는 스택이 아닌 레지스터에
					// call		set...
}
// 14 page입니다.



