#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _Name("No Name")
{
	CLASS("Constructor", "Bureaucrat");
	this->_Rank = UNDEFINED;
}

Bureaucrat::Bureaucrat(std::string name, int rank): _Name(name)
{
	CLASS("Constructor with inputs Name and Rank", "Bureaucrat");
	this->_Rank = UNDEFINED;
	changeRank(rank);
}
Bureaucrat::~Bureaucrat()
{
	CLASS("Destructor", "Bureaucrat");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _Name(other._Name)
{
	CLASS("Constructor by copy", "Bureaucrat");
	if (this == &other)
		return ;
	this->_Rank = other._Rank;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
	CLASS("Operand = Constructor", "Bureaucrat");
	if (this == &other)
		return (*this);
	this->_Rank = other._Rank;
	return (*this);
}

std::string Bureaucrat::getName()
{
	return (this->_Name);
}

void Bureaucrat::incrGrade()
{
	this->changeRank(this->_Rank - 1);
}

void Bureaucrat::decrGrade()
{
	this->changeRank(this->_Rank + 1);
}

void Bureaucrat::changeRank(int new_rank)
{
	if (new_rank < RANK_MAX)
	{
		std::cerr << RED << "For Bureaucrat " << this->_Name << ", with [" << new_rank << "] as his new grade: ";
		throw Bureaucrat::GradeTooHighException();
	}
	if (new_rank > RANK_MIN)
	{
		std::cerr << RED << "For Bureaucrat " << this->_Name << ", with [" << new_rank << "] as his new grade: ";
		throw Bureaucrat::GradeTooLowException();
	}
	this->_Rank = new_rank;
}

int Bureaucrat::getRank()
{
	return (this->_Rank);
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& guy)
{
	out << guy.getName() << ", Bureaucrat grade ";
	if (guy.getRank() == UNDEFINED)
		out << "Undefined";
	else
		out << guy.getRank();
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The new grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The new grade is too low.");
}