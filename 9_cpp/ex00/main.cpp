#include "BitcoinExchange.hpp"

int	my_key_atoi(const char *s)
{
	long	result;
	size_t	i;

	i = 0;
	result = 0;
	if (!s || !s[0])
		throw BitcoinExchange::EmptyArg();
	while (s[i] && ((s[i] <= '9' && s[i] >= '0') || s[i] == '-'))
	{
		if (s[i] != '-')
			result = result * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != ',' || result > INT_MAX)
	{
		std::cerr << "heyoo: " << s << std::endl;
		throw BitcoinExchange::BadArg();
	}
	return (result);
}

int	my_input_key_atoi(const char *s)
{
	long	result;
	size_t	i;

	i = 0;
	result = 0;
	if (!s || !s[0])
		throw BitcoinExchange::EmptyArg();
	while (s[i] && ((s[i] <= '9' && s[i] >= '0') || s[i] == '-'))
	{
		if (s[i] != '-')
			result = result * 10 + (s[i] - 48);
		i++;
	}
	if (s[i] != ' ' || result > INT_MAX)
	{
		std::cout << s << ": " ;
		throw BitcoinExchange::BadArg();
	}
	return (result);
}

float	my_input_number_atoi(const char *s)
{
	long	result;
	size_t	i;
	size_t	y;

	i = 0;
	result = 0;
	if (!s || !s[0])
		throw BitcoinExchange::EmptyArg();
	while (s[i] && s[i] != '|')
		i++;
	if (!s[i] || !s[i + 1] || s[i + 1] != ' ')
		throw BitcoinExchange::BadArg();
	i += 2;
	y = i;
	while (s[i] && ((s[i] <= '9' && s[i] >= '0') || s[i] == '.'))
	{
		if (s[i] != '.')
			result = result * 10 + (s[i] - 48);
		if (result == INT_MAX && s[i] == '.' && s[i + 1] && s[i + 1] != '0')
			throw BitcoinExchange::BadArg();
		i++;
	}
	if (s[i])
		throw BitcoinExchange::NotPositiveInt();
	if (s[i] || result > INT_MAX)
	{
		std::cerr << "hey: " << s << std::endl;
		throw BitcoinExchange::BadArg();
	}
	return (std::atof(&s[y]));
}

float	my_number_atoi(const char *s)
{
	long	result;
	size_t	i;
	size_t	y;

	i = 0;
	result = 0;
	if (!s || !s[0])
		throw BitcoinExchange::EmptyArg();
	while (s[i] && s[i] != ',')
		i++;
	if (!s[i] || !s[i + 1])
		throw BitcoinExchange::BadArg();
	i++;
	y = 0;
	size_t	pos = i;
	while (s[i] && ((s[i] <= '9' && s[i] >= '0') || s[i] == '.'))
	{
		if (s[i] != '.' && y == 0)
			result = result * 10 + (s[i] - 48);
		if (s[i] == '.')
			y++;
		i++;
	}
	if (s[i] || result > INT_MAX || y > 1)
	{
		std::cerr << "hey: " << s << std::endl;
		throw BitcoinExchange::BadArg();
	}
	return (std::atof(&s[pos]));
}

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
