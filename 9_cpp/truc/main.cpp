#include <iostream>
#include <vector>
#include <ctime>
#include <list>
#include <algorithm>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe s;

	s.VSortMergeAlgo(&argv[1], argc - 1);
	s.LSortMergeAlgo(&argv[1], argc - 1);
	return (0);
}


// 	std::vector<std::pair<int, int> > v;
// 	std::vector<std::pair<int, int> >::iterator it;
// 	std::vector<std::pair<int, int> >::iterator ite;
//     std::vector<int> numbers;
// 	std::vector<int>::iterator main_it;
// 	std::vector<int>::iterator main_ite;
// 	std::vector<int>::iterator main_ite_plus_one;
// 	std::vector<int>::iterator main_ite_minus_one;


//     for (int i = 1; i < argc; i++) {
//         try {
//             int num = std::stoi(argv[i]);
//             numbers.push_back(num);
//         } catch (const std::invalid_argument& e) {
//             std::cerr << "Invalid argument: " << argv[i] << std::endl;
//         } catch (const std::out_of_range& e) {
//             std::cerr << "Argument out of range: " << argv[i] << std::endl;
//         }
//     }
// 	//double check
// 	{
// 		std::vector<int> double_check;

// 		main_it = numbers.begin();
// 		main_ite = numbers.end();
// 		while (main_it != main_ite)
// 		{
// 			if (std::find(double_check.begin(), double_check.end(), *main_it) != double_check.end())
// 			{
// 				std::cerr << "Multiple iterations of the number " << *main_it << std::endl;
// 				return (1);
// 			}
// 			double_check.push_back(*main_it);
// 			main_it++;
// 		}
// 	}
// 	Vprint_main(numbers);
// 	return (0);
// 	// print_main(numbers);
// 	main_it = numbers.begin();
// 	main_ite = numbers.end();
// 	main_ite_plus_one = ++numbers.end();
// 	main_ite_minus_one = --numbers.end();
// 	int 	a;
// 	int	b;

// 	while (main_it != main_ite && main_it != main_ite_minus_one)
// 	{
// 		a = *main_it;
// 		++main_it;
// 		if (main_it != main_ite_plus_one)
// 			b = *main_it;
// 		else
// 			b = -42;
// 		// std::cout << "A is = " << a << " and B is = " << b << std::endl;
// 		v.push_back(std::pair<int, int>(a, b));
// 		++main_it;
// 	}

// 	int IMPAIR = 0;
// 	if (main_it == main_ite_minus_one)
// 		IMPAIR = *(main_ite_minus_one);
// 	// print(v);
// 	it = v.begin();
// 	ite = v.end();
// 	while (it != ite)
// 	{
// 		// std::cout << (*it).first << " and " << (*it).second << '\n';
// 		if ((*it).first > (*it).second)
// 			std::swap((*it).first, (*it).second);
// 		it++;
// 	}
// 	std::vector<std::pair<int, int> > map;
// 	std::vector<std::pair<int, int> >::iterator map_it;
// 	std::vector<std::pair<int, int> >::iterator map_ite;
// 	std::vector<std::pair<int, int> >::iterator map_ite_minus_one;
	
// 	map_it = map.begin();
// 	map_ite = --map.end();
// 	map.insert(map_it, *v.begin());
// 	v.erase(v.begin());
// 	map.push_back(*v.begin());
// 	v.erase(v.begin());
// 	it = v.begin();
// 	ite = v.end();
// 	if ((*map.begin()).first > (*(--map.end())).first)
// 		std::swap((*map.begin()), (*(--map.end())));
// 	while (it != ite)
// 	{
// 		if (map.size() > 1)
// 		{
// 			map_it = --map.begin();
// 			map_ite = --map.end();
// 			while ((*it).first < (*(map_ite)).first && map_ite != map_it)
// 			{
// 				map_ite--;
// 			}
// 			map.insert(++map_ite, *it);
// 		}
// 		v.erase(it);
// 		it = v.begin();
// 		ite = v.end();

// 	}
// 	std::vector<int> main_chain;
// 	// print(map);
// 	map_it = map.begin();
// 	map_ite = map.end();
// 	while (map_it != map_ite)
// 	{
// 		main_chain.push_back((*map_it).first);
// 		map_it++;
// 	}
// 	// print_main(main_chain);
// 	if (IMPAIR)
// 	{
// 			main_it = main_chain.begin();
// 			main_ite = --main_chain.end();
// 			while (IMPAIR < *(main_ite) && main_ite != main_it)
// 			{
// 				main_ite--;
// 			}
// 			main_chain.insert(++main_ite, IMPAIR);
// 	}
// 	it = map.begin();
// 	ite = map.end();

// 	while (it != ite)
// 	{
// 			main_it = main_chain.begin();
// 			main_ite = --main_chain.end();
// 			while ((*it).second < *(main_ite) && main_ite != main_it)
// 			{
// 				main_ite--;
// 			}
// 			main_chain.insert(++main_ite, (*it).second);
// 		it++;
// 	}
// 	Vprint_main(main_chain);
// }

// /*
// #include <iostream>
// #include <vector>
// #include <ctime>
// #include <list>
// #include <algorithm>


// void	print(std::list<std::pair<int, int> > v)
// {
// 	return ;
// 	std::cout << "\n hey \n";

// 	std::list<std::pair<int, int> >::iterator it;
// 	std::list<std::pair<int, int> >::iterator ite;
// 	it = v.begin();
// 	ite = v.end();
// 	while (it != ite)
// 	{
// 		std::cout << (*it).first << " and " << (*it).second << '\n';
// 		it++;
// 	}
// }

// void	print_main(std::list<int> v)
// {
// 	// return ;
// 	std::cout << "\nMAINCHIAN\n";
// 	std::list<int>::iterator it;
// 	std::list<int>::iterator ite;
// 	it = v.begin();
// 	ite = v.end();
// 	while (it != ite)
// 	{
// 		std::cout << (*it) << '\n';
// 		it++;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	std::list<std::pair<int, int> > v;
// 	std::list<std::pair<int, int> >::iterator it;
// 	std::list<std::pair<int, int> >::iterator ite;
// 	std::list<int>::iterator main_it;
// 	std::list<int>::iterator main_ite;
// 	std::list<int>::iterator main_ite_plus_one;
// 	std::list<int>::iterator main_ite_minus_one;




// 	// std::srand(std::time(NULL));
// 	// std::pair<int, int> a;

// 	// for (size_t i = 0; i < 5; i++)
// 	// {
// 	// 	v.push_back(std::pair<int, int>(std::rand() % 10000, std::rand() % 1000));
// 	// }





//     std::list<int> numbers;


//     for (int i = 1; i < argc; i++) {
//         try {
//             int num = std::stoi(argv[i]);
//             numbers.push_back(num);
//         } catch (const std::invalid_argument& e) {
//             std::cerr << "Invalid argument: " << argv[i] << std::endl;
//         } catch (const std::out_of_range& e) {
//             std::cerr << "Argument out of range: " << argv[i] << std::endl;
//         }
//     }
// 	//double check
// 	{
// 		std::list<int> double_check;

// 		main_it = numbers.begin();
// 		main_ite = numbers.end();
// 		while (main_it != main_ite)
// 		{
// 			if (std::find(double_check.begin(), double_check.end(), *main_it) != double_check.end())
// 			{
// 				std::cerr << "Multiple iterations of the number " << *main_it << std::endl;
// 				return (1);
// 			}
// 			double_check.push_back(*main_it);
// 			main_it++;
// 		}
// 	}

// 	// print_main(numbers);
// 	main_it = numbers.begin();
// 	main_ite = numbers.end();
// 	main_ite_plus_one = ++numbers.end();
// 	main_ite_minus_one = --numbers.end();
// 	int 	a;
// 	int	b;

// 	while (main_it != main_ite && main_it != main_ite_minus_one)
// 	{
// 		a = *main_it;
// 		++main_it;
// 		if (main_it != main_ite_plus_one)
// 			b = *main_it;
// 		else
// 			b = -42;
// 		// std::cout << "A is = " << a << " and B is = " << b << std::endl;
// 		v.push_back(std::pair<int, int>(a, b));
// 		++main_it;
// 	}

// 	int IMPAIR = 0;
// 	if (main_it == main_ite_minus_one)
// 		IMPAIR = *(main_ite_minus_one);
// 	// print(v);
// 	it = v.begin();
// 	ite = v.end();
// 	while (it != ite)
// 	{
// 		// std::cout << (*it).first << " and " << (*it).second << '\n';
// 		if ((*it).first > (*it).second)
// 			std::swap((*it).first, (*it).second);
// 		it++;
// 	}
// 	std::list<std::pair<int, int> > map;
// 	std::list<std::pair<int, int> >::iterator map_it;
// 	std::list<std::pair<int, int> >::iterator map_ite;
// 	std::list<std::pair<int, int> >::iterator map_ite_minus_one;
	
// 	map_it = map.begin();
// 	map_ite = --map.end();
// 	map.insert(map_it, *v.begin());
// 	v.erase(v.begin());
// 	map.push_back(*v.begin());
// 	v.erase(v.begin());
// 	it = v.begin();
// 	ite = v.end();
// 	if ((*map.begin()).first > (*(--map.end())).first)
// 		std::swap((*map.begin()), (*(--map.end())));
// 	while (it != ite)
// 	{
// 		if (map.size() > 1)
// 		{
// 			map_it = --map.begin();
// 			map_ite = --map.end();
// 			while ((*it).first < (*(map_ite)).first && map_ite != map_it)
// 			{
// 				map_ite--;
// 			}
// 			map.insert(++map_ite, *it);
// 		}
// 		v.erase(it);
// 		it = v.begin();
// 		ite = v.end();

// 	}
// 	std::list<int> main_chain;
// 	// print(map);
// 	map_it = map.begin();
// 	map_ite = map.end();
// 	while (map_it != map_ite)
// 	{
// 		main_chain.push_back((*map_it).first);
// 		map_it++;
// 	}
// 	// print_main(main_chain);
// 	if (IMPAIR)
// 	{
// 			main_it = main_chain.begin();
// 			main_ite = --main_chain.end();
// 			while (IMPAIR < *(main_ite) && main_ite != main_it)
// 			{
// 				main_ite--;
// 			}
// 			main_chain.insert(++main_ite, IMPAIR);
// 	}
// 	it = map.begin();
// 	ite = map.end();

// 	while (it != ite)
// 	{
// 			main_it = main_chain.begin();
// 			main_ite = --main_chain.end();
// 			while ((*it).second < *(main_ite) && main_ite != main_it)
// 			{
// 				main_ite--;
// 			}
// 			main_chain.insert(++main_ite, (*it).second);
// 		it++;
// 	}
// 	print_main(main_chain);
// }

// */