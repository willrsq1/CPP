#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		PresidentialPardonForm form("Adolf");
		ShrubberyCreationForm f1("stupid");
		RobotomyRequestForm f2("This_guy");
		Bureaucrat	bob("bob", 1);
		std::cout << form << std::endl;
		form.beSigned(bob);
		f1.beSigned(bob);
		f2.beSigned(bob);
		f1.execute(bob);
		f2.execute(bob);
		form.execute(bob);
		while (bob.getRank() < 50)
			bob.decrGrade();
		form.execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET_COLOR << '\n';
		return (1);
	}
	return (0);
}