#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	CLASS("Constructor", "BitcoinExchange");
}

BitcoinExchange::~BitcoinExchange()
{
	CLASS("Destructor", "BitcoinExchange");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	CLASS("Constructor by copy", "BitcoinExchange");
	if (this == &other)
		return ;
}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange& other)
{
	CLASS("Operand = Constructor", "BitcoinExchange");
	if (this == &other)
		return (*this);
	return (*this);
}

void BitcoinExchange::ft_BtcEx(std::string filename)
{
	this->GetInitData();
	this->GetFileData(filename);
}

void BitcoinExchange::GetFileData(std::string filename)
{
	std::ifstream		file(filename);
	std::string			line;

	if (!file.is_open())
		throw BitcoinExchange::BadOpen();
	std::getline(file, line);
	if (!(line == "date | value"))
		throw BitcoinExchange::BadOpen();
	while (std::getline(file, line))
	{
		try
		{
			this->DisplayValue(line);
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}

	}
}

void BitcoinExchange::DisplayValue(std::string line)
{
	int				key = my_input_key_atoi(line.c_str());

	if (checkDateError(line.substr(0,11)) == true)
		return ;
	std::map<int, float>::iterator		it = this->_Map.begin();
	std::map<int, float>::iterator		ite = this->_Map.end();

	while (it != ite && key >= (*it).first)
	{
		it++;
	}
	if (it != this->_Map.begin())
		it--;
	std::cout << line.substr(0, 10) << " => ";
	float			number = my_input_number_atoi(line.c_str());
	std::cout << number << " = " << (*it).second * number <<std::endl;
}

void BitcoinExchange::GetInitData()
{
	std::ifstream		file("data.csv");
	std::string			line;
	int					key;
	float				number;
	std::pair<int, int> p;

	if (!file.is_open())
		throw BitcoinExchange::BadOpen();
	std::getline(file, line);
	if (!(line == "date,exchange_rate"))
		throw BitcoinExchange::BadOpen();
	while (std::getline(file, line))
	{
		try
		{
			key = my_key_atoi(line.c_str());
			number = my_number_atoi(line.c_str());
			if (checkDateError(line.substr(0, 11)) == true)
				throw BitcoinExchange::BadArg();
		}
		catch (const std::exception& e)
		{
			std::cout << "At line: " << line << ": ";
			std::cout << "Error: " << e.what() << std::endl;
			throw e;
		}
		this->_Map.insert(std::make_pair(key, number));
	}
}

bool BitcoinExchange::checkDateError(const std::string &date)
{
	if (date.length() != 11) {
		std::cerr  << "Error: invalid date format"  << std::endl;
		return true;
	}
	for (size_t i = 0; i < date.length() - 1; i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-') {
				std::cerr  << "Error: invalid date format"  << std::endl;
				return true;
			}
		}
		else if (!std::isdigit(date[i])) {
			std::cerr  << "Error: invalid date format"  << std::endl;
			return true;
		}
	}
	int day, month, year;
	year = atoi(date.c_str());
	month = atoi(date.c_str() + 5);
	day = atoi(date.c_str() + 8);
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(year)) {
		days[1] = 29;
	}
	if (month < 1 || month > 12) {
		std::cerr  << "Error: invalid month"  << std::endl;
		return true;
	}
	if (day < 1 || day > days[month - 1]) {
		std::cerr  << "Error: invalid day"  << std::endl;
		return true;
	}
	return false;
}

const char * BitcoinExchange::BadOpen::what() const throw()
{
	return ("File couldn't be opened");
}

const char * BitcoinExchange::EmptyArg::what() const throw()
{
	return ("Empty line detected");
}

const char * BitcoinExchange::BadArg::what() const throw()
{
	return ("Line improperly formated");
}

const char * BitcoinExchange::BadFirstLine::what() const throw()
{
	return ("The first line of the file isn't the requested input ([data, exchange_rate] OR [data | value] for input file).");
}

const char * BitcoinExchange::NotPositiveInt::what() const throw()
{
	return ("Not a positive int");
}

int	 BitcoinExchange::my_key_atoi(const char *s)
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
	if (s[i] != ',' || result > INT_MAX || i != 10)
	{
		std::cerr << s << std::endl;
		throw BitcoinExchange::BadArg();
	}
	return (result);
}

int	 BitcoinExchange::my_input_key_atoi(const char *s)
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

float	 BitcoinExchange::my_input_number_atoi(const char *s)
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
		std::cerr << s << std::endl;
		throw BitcoinExchange::BadArg();
	}
	return (std::atof(&s[y]));
}

float	 BitcoinExchange::my_number_atoi(const char *s)
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
		std::cerr << s << std::endl;
		throw BitcoinExchange::BadArg();
	}
	return (std::atof(&s[pos]));
}


bool BitcoinExchange::isLeapYear(unsigned int year)
{
	if (year % 4 != 0)
		return false;
	if (year % 100 != 0)
		return true;
	if (year % 400 != 0)
		return false;
	return true;
}