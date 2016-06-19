// 23_defaule_comparsion

// 생성자, 소멸자, 복사 생성자, 복사 대입연산자, 이동생성자, 이동 대입연산자
// ==, !=, <, <=, >, >=

// 포인터의 경우 ?
// 참조 일경우 ?
// private 멤버 ?
// 상속이 있을때는 ?
// 사용자가 != 만 제공할때 default 버전의 == 는 ?
// empty class ?
// union ?

struct Point
{
	int x, y;
};

int main()
{
	Point p1, p2;

	bool b = (p1 == p2);
}