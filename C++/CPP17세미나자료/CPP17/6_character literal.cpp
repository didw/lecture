#include <iostream>
using namespace std;

int main()
{
	char s1[] = u8"hello";  // UTF-8  ISO 10646

	char16_t s2[] = u"hello"; // UTF-16

	char32_t s3[] = U"hello"; // UTF-32

	wchar_t s4[] = L"hello";  // wide character set

	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;
	cout << sizeof(s3) << endl;
	cout << sizeof(s4) << endl;
}

/*
A character literal that begins with the letter u, such as u'y', 
is a character literal of type char16_t.

The value of a char16_t literal containing a single c - char is 
equal to its ISO 10646 code point value, provided that the code point is representable 
with a single 16 - bit code unit. 
(That is, provided it is a basic multi - lingual plane code point.) 
If the value is not representable within 16 bits, the program is ill - formed.
A char16_t literal containing multiple c - chars is ill - formed.

A character literal that begins with the letter U, such as U'z', 
is a character literal of type char32_t.
The value of a char32_t literal containing a single c - char is equal to its ISO 10646 
code point value.A char32_t literal containing multiple c - chars is ill - formed.


A character literal that begins with the letter L, such as L'x', 
is a wide - character literal.
A wide - character literal has type wchar_t.
[Footnote:¡¦] 
The value of a wide - character literal containing a single c - char has value equal to 
the numerical value of the encoding of the c - char in the execution wide - character set, 
unless the c - char has no representation in the execution wide - character set, 
in which case the value is implementation - defined.
[Note:The type wchar_t is able to represent all members of the execution wide - character set(see 3.9.1).].The value of a wide - character literal containing multiple c - chars is implementation - defined.

*/