#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery Creation Form", 145, 137)
{
	CLASS("Constructor", "ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery Creation Form", 145, 137)
{
	this->_Target = target;
	CLASS("Constructor", "ShrubberyCreationForm with input target");
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	CLASS("Destructor", "ShrubberyCreationForm");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): Form("Shrubbery Creation Form", 145, 137)
{
	CLASS("Constructor by copy", "ShrubberyCreationForm");
	if (this == &other)
		return ;
	this->setSigned(other.getSigned());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& other)
{
	CLASS("Operand = Constructor", "ShrubberyCreationForm");
	if (this == &other)
		return (*this);
	this->setSigned(other.getSigned());
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	this->checkPermissions(executor);
	
	std::string	filename = this->_Target + "_shrubbery";
	std::ofstream 	file(filename.c_str());

	if (!file.is_open())
		throw ShrubberyCreationForm::OpenShrubberyError();
	file << "AsCII TREES";
	file.close();
	std::cout << BLUE << this->_Target + "_shrubbery " << "has been filled with ascii trees." << RESET_COLOR << std::endl; 
}

const char* ShrubberyCreationForm::OpenShrubberyError::what() const throw()
{
	return ("Couldn't open the file.");
}
