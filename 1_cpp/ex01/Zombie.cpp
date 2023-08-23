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
}

Zombie::Zombie(std::string given_name)
{
	name = given_name;
}

Zombie::~Zombie()
{
	std::cout << "Destructed: " << name << std::endl;
}