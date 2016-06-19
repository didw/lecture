// -> : 스마트 포인터의 핵심 
// .   : 스마트 reference

template<class X>
class Ref 
{
public:
	Ref(int a) :p{ new X{ a } } {}
	X& operator.() { /* maybe some code here */ return *p; }
	~Ref() { delete p; }

	void rebind(X* pp) { delete p; p = pp; }
	// …
private:
	X* p;
};

Ref<X> x{ 99 };

x.f(); // means (x.operator.()).f() means (*x.p).f()

x = X{ 9 }; // means x.operator.() = X{9} means (*x.p )=X{9}