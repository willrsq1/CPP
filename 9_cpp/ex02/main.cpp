#include <iostream>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Not a valid arg (not a sequence of positive ints).\n";
		return (1);
	}
	if (TEMPLATE)
	{
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> >> s;

		try
		{
			s._SortStack(&argv[1], argc - 1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception:" << e.what() << '\n';
		}
		
	}
	else
	{

	}
	return (0);
}
