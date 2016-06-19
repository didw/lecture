#include <vector>
#include <iostream>
using namespace std;

int main()
{
	std::vector<int> v = { 1,2,3 };

	// standard sequential sort
	std::sort(v.begin(), v.end());


	// explicitly sequential sort
	sort(seq, v.begin(), v.end());

	// permitting parallel execution
	sort(par, v.begin(), v.end());
	
	// permitting vectorization as well
	sort(par_vec, v.begin(), v.end());
	
	// sort with dynamically-selected execution
	size_t threshold = ...
	
	execution_policy exec = seq;

	if (v.size() > threshold)
	{
		exec = par;
	}
	sort(exec, v.begin(), v.end());

}