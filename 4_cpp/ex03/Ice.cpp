#include "Ice.hpp"

Ice::Ice()
{
	CLASS("Constructor", "Ice");
}

Ice::~Ice()
{
	CLASS("Destructor", "Ice");
}

Ice::Ice(const Ice& other)
{
	CLASS("Constructor by copy", "Ice");
}

Ice& Ice::operator= (const Ice& other)
{
	CLASS("Operand = Constructor", "Ice");
	if (this == &other)
		return (*this);
	return (*this);
}
