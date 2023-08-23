#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string given_name)
{
	name = given_name;
}

Zombie::Zombie()
{
	name = "name";
	std::cout << "I was created in first constructor" << std::endl;
}

Zombie::Zombie(std::string given_name)
{
	name = given_name;
	std::cout << "I was created in second constructor: " << name << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Was destructed: " << name << std::endl;
}