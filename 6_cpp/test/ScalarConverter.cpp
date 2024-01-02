#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    CLASS("Constructor", "ScalarConverter");
}

ScalarConverter::~ScalarConverter()
{
    CLASS("Destructor", "ScalarConverter");
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    CLASS("Constructor by copy", "ScalarConverter");
    if (this == &other)
        return ;
}

ScalarConverter& ScalarConverter::operator= (const ScalarConverter& other)
{
    CLASS("Operand = Constructor", "ScalarConverter");
    if (this == &other)
        return (*this);
    return (*this);
}

void ScalarConverter::convert(const std::string &input)
{
	if (input.empty())
	{
		std::cout << "Input can't be empty" << std::endl;
		return ;
	}
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "inf" || input == "inff" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (ScalarConverter::isFloat(input))
		ScalarConverter::convertFloat(input);
	else if (ScalarConverter::isDouble(input))
		ScalarConverter::convertDouble(input);
	else if (ScalarConverter::isInt(input))
		ScalarConverter::convertInt(input);
	else if (ScalarConverter::isChar(input))
		ScalarConverter::convertChar(input);
	else
		std::cout << ("Not a valid decimal representation of neither char, int, double, nor float.");	
}

bool ScalarConverter::isFloat(const std::string &input)
{
	size_t	pos;

	pos = input.find('.');
	if (pos == std::string::npos || pos == input.length() - 1)
		return (0);
	if (!(input.length() >= 2 && input[input.length() - 1] == 'f' && input[input.length() - 2] != '.'))
			return (0);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			i++;
		if (!std::isdigit(input[i]) && \
			!(input[i] == '.' && i == pos) && \
			!(input[i] == 'f' && i == input.length() - 1))
			return (0);
	}
	return (1);
}

bool ScalarConverter::isDouble(const std::string &input)
{
	size_t	pos;

	pos = input.find('.');
	if (pos == std::string::npos || pos == input.length() - 1)
		return (0);
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			i++;
		if (!std::isdigit(input[i]) && \
			!(input[i] == '.' && i == pos))
			return (0);
	}
	return (1);
}

bool ScalarConverter::isInt(const std::string &input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (i == 0 && (input[i] == '-' || input[i] == '+'))
			i++;
		if (!std::isdigit(input[i]))
			return (0);
	}
	return (1);
}


bool ScalarConverter::isChar(const std::string &input)
{
    if (std::isprint(input[0]) && input.length() == 1)
		return (1);
	return (0);
}




void ScalarConverter::convertChar(const std::string &input)
{
	std::istringstream iss(input);
    char c;

    if (!(iss >> c))
    {
        std::cout << "char: 'Non Displayable'" << std::endl;

        int a;
        iss >> a;
        std::cout << "int: " << a << std::endl;
        std::cout << "float: " << static_cast<float>(a) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(a) << ".0" << std::endl;

        std::cerr << "\033[1;31m" << "Char Overflowed" << "\033[0m" << std::endl;
        return;
    }

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(const std::string &input)
{
   	std::istringstream iss(input);
    int i;

    if (!(iss >> i))
    {
        std::cout << "char: 'Int Overflowed'" << std::endl;
        std::cout << "int: 'Overflowed'" << std::endl;
        std::cout << "float: 'Int Overflowed'" << std::endl;
        std::cout << "double: 'Int Overflowed'" << std::endl;

        std::cerr << "\033[1;31m" << "Int overflowed !" << "\033[0m" << std::endl;
        return;
    }

    if (i >= 32 && i < 127)
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    else
        std::cout << "char: 'Non Displayable'" << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(const std::string &input)
{
    std::istringstream iss(input);
    float f;

    if (!(iss >> f))
    {
        std::cout << "char: 'Error'" << std::endl;
        std::cout << "int: 'Error'" << std::endl;
        std::cout << "float: 'Error: Overflow'" << std::endl;
        std::cout << "double: 'Error'" << std::endl;

        std::cerr << "\033[1;31m" << "Float Overflowed" << "\033[0m" << std::endl;
        return;
    }

    // if (f > static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min()))
    //     std::cout << "int: 'Overflow'" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << "float: " << f << ((f == static_cast<float>(static_cast<int>(f))) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << static_cast<double>(f) << ((f == static_cast<float>(static_cast<int>(f))) ? ".0" : "") << std::endl;
}

void ScalarConverter::convertDouble(const std::string &input)
{
    std::istringstream iss(input);
    double d;

    if (!(iss >> d))
    {
        std::cout << "char: 'Error'" << std::endl;
        std::cout << "int: 'Error'" << std::endl;
        std::cout << "float: 'Error'" << std::endl;
        std::cout << "double: 'Error: Overflow'" << std::endl;

        std::cerr << "\033[1;31m" << "Double Overflowed" << "\033[0m" << std::endl;
        return;
    }

    // if (d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()))
    //     std::cout << "int: 'Overflow'" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << "float: " << static_cast<float>(d) << ((d == static_cast<double>(static_cast<int>(d))) ? ".0f" : "f") << std::endl;
    std::cout << "double: " << d << ((d == static_cast<double>(static_cast<int>(d))) ? ".0" : "") << std::endl;
}