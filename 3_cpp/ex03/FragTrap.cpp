#include "FragTrap.hpp"


FragTrap::FragTrap()
{
	std::cout << "Called FragTrap Constructor" << std::endl;
	this->Name = "Noname";
	this->AttackDamage = 30;
	this->EnergyPoints = 100;
	this->HitPoints = 100;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "Called FragTrap Constructor with Name Input" << std::endl;
	this->Name = name;
	this->AttackDamage = 30;
	this->EnergyPoints = 100;
	this->HitPoints = 100;
}

FragTrap::~FragTrap()
{
	std::cout << "Called FragTrap Destructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	std::cout << "Called FragTrap Copy Constructor" << std::endl;
	this->Name = other.Name;
	this->AttackDamage = other.AttackDamage;
	this->EnergyPoints = other.EnergyPoints;
	this->HitPoints = other.HitPoints;
}

FragTrap& FragTrap::operator= (const FragTrap& other)
{
	std::cout << "Called FragTrap Copy Assignment Operator" << std::endl;
	if (this == &other)
		return (*this);
	this->Name = other.Name;
	this->AttackDamage = other.AttackDamage;
	this->EnergyPoints = other.EnergyPoints;
	this->HitPoints = other.HitPoints;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->HitPoints <= 0)
	{
		std::cerr << "FragTrap " << this->Name << " is dead. It can't ask for high fives." << std::endl;
		return ;
	}
	if (this->EnergyPoints <= 0)
	{
		std::cerr << "FragTrap " << this->Name << " is out of energy. It can't ask for high fives." << std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	std::cout << "Hey guys ! I'm " << this->Name << ", will you high-five me ?" << std::endl;
}
