// 3_const5 - 7 page

class Point
{
public:
	int x, y;
	void set(int a, int b) 	{ 	x = a;	y = b;	}

	void print() const
	{
	//	x = 10; // error. 상수 함수에서는 멤버의 값을 변경할수 없다.
		cout << x << ", " << y << endl;
	}
};
int main()
{
	const Point p; // 상수 객체
	p.x = 10;		// error.
	p.set(10, 20);	// error
	p.print();		// error. 호출 할수 있게 하려면 print함수는 상수함수이어야한다
					// "상수 객체는 상수 함수만 호출할수 있다."
}





