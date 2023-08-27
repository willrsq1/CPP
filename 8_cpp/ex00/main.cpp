#include "easyfind.hpp"

int main()
{
	std::vector<int>	v(300);

	std::fill(v.begin(), v.end(), 10);
	std::fill(v.begin(), v.end() - 10, 15);
	easyfind(v, 10);
	std::vector<int> s(1000);
	try
	{
		easyfind(s, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
