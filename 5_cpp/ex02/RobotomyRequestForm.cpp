#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 72, 45)
{
	CLASS("Constructor", "RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("Robotomy Request Form", 72, 45)
{
	this->_Target = target;
	CLASS("Constructor", "RobotomyRequestForm with input target");
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	CLASS("Destructor", "RobotomyRequestForm");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): Form("Robotomy Request Form", 72, 45)
{
	CLASS("Constructor by copy", "RobotomyRequestForm");
	if (this == &other)
		return ;
	this->setSigned(other.getSigned());
}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& other)
{
	CLASS("Operand = Constructor", "RobotomyRequestForm");
	if (this == &other)
		return (*this);
	this->setSigned(other.getSigned());
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	this->checkPermissions(executor);
	std::cout << BLUE << "* ZBZBRBZBZBRZBBRZBRBZ *perceuse*" << std::endl << this->_Target;
	if (std::rand() % 2)
		std::cout << " has been robotomized !" << std::endl;
	else
		std::cout << ": The operation has failed." << std::endl;
	std::cout << RESET_COLOR;
}
