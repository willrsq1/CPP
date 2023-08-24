#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(/* args */)
{
	std::cout << "Called Diamond Trap Constructor" << std::endl;
	this->_Name = "No_name";
	this->_HitPoints = this->HitPoints;
	this->_EnergyPoints = get_EP();
	this->_AttackDamage = this->AttackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "Called Diamond Trap Constructor with Name Input" << std::endl;
	this->_Name = name;
	ClapTrap::_Name = name + "_clap_name";
	this->_HitPoints = this->HitPoints;
	this->_EnergyPoints = get_EP();
	this->_AttackDamage = this->AttackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Called Diamond Trap Destructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(), FragTrap(), ScavTrap() 
{
	std::cout << "Called Diamond Trap Copy Constructor" << std::endl;
	this->_Name = other._Name;
	ClapTrap::_Name = this->_Name + "_clap_name";
	this->_HitPoints = other.HitPoints;
	this->_EnergyPoints = get_EP();
	this->_AttackDamage = other.HitPoints;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_Name << " and my grandfather ClapTrap's name is " << ClapTrap::show_Name() << std::endl;
}

void DiamondTrap::show_Hit_Points()
{
	std::cout << "DiamondTrap Hit Points = " << this->_HitPoints << std::endl;
}

void DiamondTrap::show_Energy_Points()
{
	std::cout << "DiamondTrap Energy Points = " << this->_EnergyPoints << std::endl;
}

void DiamondTrap::show_Attack_Damage()
{	
	std::cout << "DiamondTrap Attack Damage = " << this->_AttackDamage << std::endl;
}