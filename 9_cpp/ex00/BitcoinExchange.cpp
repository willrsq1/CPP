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
