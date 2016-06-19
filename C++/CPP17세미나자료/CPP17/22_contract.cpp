// 22_contract
// not error reporting mechanism
// not type system
// not testing framework

// like assert()

// pre-condition : expects
// post-condition : ensures


template<typename T> class ArrayView
{
	void foo(int age)
	{
		assert(age > 0);

	}


	T& operator[](size_t i)[[expects:i < size()]];




	ArrayView(const vector<T>& v)[[ensures:data() == v.data()]];
};

// examples
struct A 
{
	bool f() const;
	bool g() const;
	virtual string bhar()[[expects:f() && g()]];
	virtual int hash()[[ensures:g()]];
	virtual void gash()[[expects:g()]];
	virtual double fash(int i) const[[expects:i > 0]];
};
struct B : A 
{
	string bhar() override[[expects:f()]]; // ERROR: weakening.
	int hash() override[[ensures:f() && g()]]; // ERROR: strengthening.
	void gash() override[[expects:g()]]; // OK: repeat from base.
	double fash(int) override; // OK: inherited from base.
};