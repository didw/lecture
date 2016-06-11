// 9_override
class Base
{
public:
	virtual void foo(int a) {}
	virtual void goo() const {}
	virtual void hoo() {}
	void koo() {}
};
/*
class Derived : public Base
{
public:
	// 아래 코드를 생각해보세요
	virtual void foo(double) {}
	virtual void goo() {}
	virtual void hooo() {}
	virtual void koo() {}
};
*/

class Derived : public Base
{
public:
	virtual void foo(double) override {}
	virtual void goo() const override {}
	virtual void hooo()override {}
	virtual void koo() override {}
};

int main() {}
// 220 page


