// m1.cpp
module M1;
export int f(int, int);
int g(int x)        {return x * x;}
int f(int x, int y) {return g(x) + g(y);}


// m2.cpp
module M2;
export bool g(int, int);
import std.math;
int f(int x, int y) { return x + y;}
int g(int x, int y) { return f(abs(x), abs(y));}

// main.cpp
//#include "m1.h"
import M1;
import M2;
import std.vector;

int main()
{
	return f(3, 4) + g(3, 4);
}