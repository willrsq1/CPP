#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	make_the_exec_a_noob(Bureaucrat executor)
{
	while (executor.getRank() < 150)
		executor.decrGrade();
}

void	get_a_form_signed(Form *form, Bureaucrat executor)
{
	while (executor.getRank() > form->getSignGrade())
		executor.incrGrade();
	form->beSigned(executor);
	while (executor.getRank() > form->getExecGrade())
		executor.incrGrade();
	executor.executeForm(*form);
	form->execute(executor);
}

int	main()
{
	Form* rrf = NULL;

	try
	{
		Intern someRandomIntern;
		Bureaucrat	bob("BOB", 3);
		rrf = someRandomIntern.makeForm(ROBO, "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm(PRESI, "Finn");
		std::cout << *rrf << std::endl;
		delete rrf;
		rrf = someRandomIntern.makeForm(SHRUB, "Finn");
		std::cout << *rrf << std::endl;
		rrf->beSigned(bob);
		bob.executeForm(*rrf);
		bob.signForm(*rrf);
		rrf->execute(bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET_COLOR << '\n';
	}
	if (rrf)
		delete rrf;
	return (0);
}