
// 일반 함수도 지울수 있습니다.
// 함수를 제공하지 않은것 : 인자가 암시적 형변환 되어서 다른 함수를 호출가능
//       삭제하는 것     : 암시적 형변환 되기 전에 삭제 되었다는 것을 알기 때문에
//							컴파일 에러.
void foo(int a) {}
//void foo(double) = delete;

template<typename T> void goo(T a) {}
void goo(double) = delete;

int main()
{
	foo(3);
	foo(3.4);
}