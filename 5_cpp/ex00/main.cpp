#include "Bureaucrat.hpp"

int	main()
{
	try
	{
	
	
	Bureaucrat	boy("Claude", 130);
	Bureaucrat	girl("Cercei", 10);
	Bureaucrat	girl2("luci", 1);

	std::cout << boy << std::endl;
	std::cout << girl << std::endl;
	std::cout << girl2 << std::endl;
	Bureaucrat	boy2("ClaudeTwo", 20);

	for (size_t i = 0; i < 25; i++)
	{
		boy.decrGrade();
		boy2.incrGrade();
		std::cout << boy << std::endl;
		std::cout << boy2 << std::endl;
	}
	boy = boy2;
	Bureaucrat boy3(boy);
	std::cout << boy << std::endl;
	std::cout << boy3 << std::endl;
	Bureaucrat boy4("Jack", 0);
	std::cout << boy4 << std::endl;
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}