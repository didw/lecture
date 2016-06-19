// strong type을 만드는 기술..

enum class Color : int { red =1, green = 2};

int main()
{
	Color c = red; // error
}


enum class byte : unsigned char { };

enum class HWND : unsigned int {};
enum class HPEN : unsigned int {};

void foo(HWND h) {}

int main()
{
//	byte b1{ 42 }; // error
	byte b2{ static_cast<byte>(42) }; // OK

	HPEN hPen = static_cast<HPEN>(30);

	foo(hPen);
}
