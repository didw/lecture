// 3_const5 - 7 page

class Point
{
public:
	int x, y;
	void set(int a, int b) 	{ 	x = a;	y = b;	}

	void print() const
	{
	//	x = 10; // error. ��� �Լ������� ����� ���� �����Ҽ� ����.
		cout << x << ", " << y << endl;
	}
};
int main()
{
	const Point p; // ��� ��ü
	p.x = 10;		// error.
	p.set(10, 20);	// error
	p.print();		// error. ȣ�� �Ҽ� �ְ� �Ϸ��� print�Լ��� ����Լ��̾���Ѵ�
					// "��� ��ü�� ��� �Լ��� ȣ���Ҽ� �ִ�."
}





