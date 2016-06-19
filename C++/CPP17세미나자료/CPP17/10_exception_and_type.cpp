
void foo() {}
void goo() noexcept {}

void hoo() throw(int) 
{
}

int main()
{
	void(*f)() throw() = &hoo;   // not currently an error

	void(*f1)() = &foo;
	void(*f2)() = &goo;

//	void(*f3)()noexcept = &foo;
	void(*f4)()noexcept = &goo;

}
