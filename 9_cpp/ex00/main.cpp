#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Please follow the requested format: ./btc [filename.csv]" << std::endl;
		return (1);
	}
	BitcoinExchange	b;
	try
	{
		b.ft_BtcEx(argv[1]);
	}
	catch (const std::exception& e)
	{
		// std::cout << "Exception catched: " << e.what() << std::endl;
		return (1);
	}
	if (argv)
		return (0);
	return (0);
}
