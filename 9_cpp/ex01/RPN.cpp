#include "RPN.hpp"

RPN::RPN()
{
	CLASS("Constructor", "RPN");
}

RPN::~RPN()
{
	CLASS("Destructor", "RPN");
}

RPN::RPN(const RPN& other)
{
	CLASS("Constructor by copy", "RPN");
	if (this == &other)
		return ;
	this->_Numbers = other._Numbers;
}

RPN& RPN::operator= (const RPN& other)
{
	CLASS("Operand = Constructor", "RPN");
	if (this == &other)
		return (*this);
	this->_Numbers = other._Numbers;
	return (*this);
}

void RPN::_FtCalcul(std::string s)
{
	std::list<int>::iterator	ite;
	long long	number;
	long long	stl;

	if (this->_Numbers.size() == 1)
		throw RPN::InputNotFormatedWell();
	number = this->_Numbers.back();
	this->_Numbers.pop_back();
	stl = this->_Numbers.back();
	if (s == "+")
		stl += number;
	else if (s == "-")
		stl -= number;
	else if (s == "*")
		stl *= number;
	else if (s == "/")
	{
		if (number == 0)
			throw RPN::DivisionByZero();
		stl /= number;
	}
	if (stl > INT_MAX || stl < INT_MIN)
	{
		std::cout << this->_Numbers.back() << " " << s << " " << number << " = " << stl << ": ";
		throw RPN::OutOfRange();
	}
	this->_Numbers.pop_back();
	this->_Numbers.push_back(stl);
}

void RPN::_RPNCalculation(std::list<std::string> lst)
{
	ListInit(lst);
	if (this->_Numbers.size() != 1)
		throw RPN::MissingOperators();
	std::cout << "Result is: " << *(this->_Numbers.begin()) << std::endl;
}

void RPN::ListInit(std::list<std::string> lst)
{
	std::string	s;
	std::list<std::string>::iterator		it = lst.begin();
	std::list<std::string>::iterator		ite = lst.end();

	while (it != ite)
	{
		try
		{
			this->_Numbers.push_back(my_atoi((*it).c_str()));
		}
		catch (...)
		{
			if (!is_operator(*it))
				throw RPN::BadOp();
			_FtCalcul(*it);
		}
		it++;
	}
}

const char * RPN::BadArg::what() const throw()
{
	return ("hello bad arg");
}
const char * RPN::BadOp::what() const throw()
{
	return ("The input in improperly formated, only numbers (positive ints) and operands are allowed");
}
const char * RPN::Empty::what() const throw()
{
	return ("hello empty arg");
}
const char * RPN::InputNotFormatedWell::what() const throw()
{
	return ("The input is missing numbers");
}
const char * RPN::MissingOperators::what() const throw()
{
	return ("The input is missing operators, too many numbers in stack at the end");
}
const char * RPN::OutOfRange::what() const throw()
{
	return ("The result is out of range (not an int)");
}
const char * RPN::DivisionByZero::what() const throw()
{
	return ("Unallowed divsion by zero");
}