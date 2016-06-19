
// typename for template template parameter
template<typename T> class list {};

template<typename T, template<typename> typename C> class stack
{

};

int main()
{
	stack<int, list> 
}