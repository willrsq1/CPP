#include "AMetaria.hpp"

AMetaria::AMetaria()
{
	CLASS("Constructor", "AMetaria");
}

AMetaria::~AMetaria()
{
	CLASS("Destructor", "AMetaria");
}

AMetaria::AMetaria(const AMetaria& other)
{
	CLASS("Constructor by copy", "AMetaria");
}

AMetaria& AMetaria::operator= (const AMetaria& other)
{
	CLASS("Operand = Constructor", "AMetaria");
	if (this == &other)
		return (*this);
	return (*this);
}
