


// ��� �Լ��� ������ �ƴ� �ʼ� �Դϴ�.
// ��ü�� ����(��� data)�� �������� ���� ��� �Լ���(getXXXX) �� �ݵ��
// ����Լ��� �Ǿ�� �մϴ�.

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
	Rect r; // �ʱ�ȭ �ߴٰ� �����ϰ�
	int n = r.getArea();
	foo(r);
}



