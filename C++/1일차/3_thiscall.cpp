// 3_thiscall - 13 page ~

class Point
{
	int x, y;
public:
	void set(int a, int b) // void set( Point* const this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;  // this->y = b; ��� ������ �˴ϴ�.
	}

	static void foo(int a)// void foo(int a)
	{
		x = a;	// this->x = a; �� �����ؾ� �ϴµ� this�� ����. error
	}
};
int main()
{
	Point::foo(10);  // ��ü ���� ȣ��

	Point p1, p2;
	p1.set(10, 20); // �� ������ ������ ������ ���ô�.
					// set(&p1, 10, 20)���� ���ϰ� �˴ϴ�.
					// push		20
					// push		10
					// mov      ecx, &p1  ��ü �ּҴ� ������ �ƴ� �������Ϳ�
					// call		set...
}
// 14 page�Դϴ�.



