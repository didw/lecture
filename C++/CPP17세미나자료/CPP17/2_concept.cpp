
// template without Concept
template<LessThanComparable T>
const T& min(const T &x, const T &y) 
{
	return (y < x) ? y : x;
}




//---------------------------------------
// concept definition
auto concept LessThanComparable<typename T> 
{
	bool operator<(T, T);
}

// template with concept
template<typename T> requires LessThanComparable<T>
const T& min(const T &x, const T &y) 
{
		return (y < x) ? y : x;
}

// composed concept
concept InputIterator<typename Iter, typename Value> 
{
	requires Regular<Iter>;
	Value operator*(const Iter&);
	Iter& operator++(Iter&);
	Iter operator++(Iter&, int);
}

// derived concept
concept ForwardIterator<typename Iter, typename Value>
			: InputIterator<Iter, Value>
{
	// Add other requirements here.
}