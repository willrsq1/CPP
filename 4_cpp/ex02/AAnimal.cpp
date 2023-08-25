#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	CLASS("Constructor", "AAnimal");
	this->type = "No type";
	this->brain_ptr = NULL;
}

AAnimal::~AAnimal()
{
	CLASS("Destructor", "AAnimal");
	if (this->brain_ptr)
		delete this->brain_ptr;
	this->brain_ptr = NULL;
}

AAnimal::AAnimal(const AAnimal& other)
{
	CLASS("Constructor by copy", "AAnimal");
	this->type = other.type;
	if (other.brain_ptr)
		this->brain_ptr = new Brain(*other.brain_ptr);
}

AAnimal& AAnimal::operator= (const AAnimal& other)
{
	CLASS("Operand = Constructor", "AAnimal");
	if (this == &other)
		return (*this);
	this->type = other.type;
	if (other.brain_ptr)
		this->brain_ptr = new Brain(*other.brain_ptr);
	return (*this);
}

void AAnimal::makeSound() const
{
	if (this->type == "Cat")
		std::cout << "Meooooooow" << std::endl;
	if (this->type == "Dog")
		std::cout << "Waf waf waf" << std::endl;
	else
		std::cout << "......" << std::endl;
}

std::string	AAnimal::getType() const
{
	return (this->type);
}
