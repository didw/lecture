
// E : parameter pack ( args )
// op : operator
// I : init
1) Unary  right fold(E op ...) becomes E1 op (... op(En-1 op En))
2) Unary  left fold(... op E) becomes((E1 op E2) op ...) op En
3) Binary right fold(E op ... op I) becomes E1 op(... op(En−1 op(En op I)))
4) Binary left fold(I op ... op E) becomes(((I op E1) op E2) op ...) op En

// Sample 1.
template<typename... Args> bool all(Args... args) 
{ 
	return (... && args); 
}

int main()
{
	bool b = all(true, true, true, false); 
	        // (( true && true) && true) && false
}

// Sample 2.
template<typename ...Args> int sum(Args&&... args) 
{
	return (args + ... + (1* 2)); 
}
int main()
{
	sum(1, 2, 3, 4); // (1+(2+(3+(4+(1*2))))
}

// Sample 3.
#include <iostream>
#include <vector>

template<typename ...Args>
void printer(Args&&... args) 
{
	(std::cout << ... << args) << '\n';
}

int main()
{
	printer(1, 2, 3, "abc"); 
}

