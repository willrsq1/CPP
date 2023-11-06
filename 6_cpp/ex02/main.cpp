#include "Base.hpp"

int		main()
{
	Base * ptr = Base::generate();
	Base::identify(ptr);
	Base::identify(NULL);
	Base::identify(*ptr);
	Base::identify(NULL);
	delete ptr;

	for (size_t i = 0; i < 3; i++)
	{
		ptr = Base::generate();
		std::cout << "New generation." << std::endl;
		Base::identify(ptr);
		Base::identify(*ptr);
		Base::identify(*&*&*&*&*&*&*&*&*&*&*&*ptr);
		delete ptr;
	}
		
}
