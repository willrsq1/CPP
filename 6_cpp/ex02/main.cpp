#include "Base.hpp"

int		main()
{
	Base * ptr = Base::generate();
	Base::identify(ptr);
	Base::identify(NULL);
	Base::identify(*ptr);
	Base::identify(NULL);
	delete ptr;

	for (size_t i = 0; i < 10; i++)
	{
		ptr = Base::generate();
		Base::identify(ptr);
		Base::identify(*ptr);
		Base::identify(*&*&*&*&*&*&*&*&*&*&*&*ptr);
		delete ptr;
	}
		
}
