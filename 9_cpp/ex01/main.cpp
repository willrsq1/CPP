#include "RPN.hpp"

bool	is_operator(std::string s)
{
	if (s == "+" || s == "-" || s == "*" || s== "/")
		return (1);
	return (0);
}

int	my_atoi(const char *s)
{
	long	result;
	size_t	i;

	i = 0;
	result = 0;
	if (!s || !s[0])
		throw RPN::Empty();
	while (s[i] && s[i] == '0')
		i++;
	while (s[i] && s[i] <= '9' && s[i] >= '0')
	{
		result = result * 10 + (s[i] - 48);
		if (result > INT_MAX)
			throw RPN::BadArg();
		i++;
	}
	if (s[i] || result > INT_MAX)
	{
		throw RPN::BadArg();
	}
	return (result);
}

std::list<std::string> split(const std::string &str, char delimiter) 
{
    std::list<std::string> result;
    std::string token;
    
    for (size_t i = 0; i < str.length(); ++i)
	{
        if (str[i] != delimiter)
		{
            token += str[i];
        }
		else 
		{
            if (!token.empty())
			{
                result.push_back(token);
                token.clear();
            }
        }
    }
    if (!token.empty())
	{
        result.push_back(token);
    }
    return result;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please follow the requested format: ./RPN [arg]" << std::endl;
		return (1);
	}
	RPN		r;
	std::list<std::string>		args = split(argv[1], ' ');

	if (args.empty())
	{
		std::cout << "Empty input" << std::endl;
		return (1);
	}
	try {
		r._RPNCalculation(args);
	} catch (const std::exception& e)
	{
		std::cout << "Exception catched: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
