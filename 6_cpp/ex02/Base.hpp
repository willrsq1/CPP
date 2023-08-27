#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# ifndef CLASS
#  define CLASS(x, y) std::cout << ""
// #  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# define RED	"\033[1;31m"
# define BLUE "\033[1;36m"
# define RESET_COLOR "\033[0m"

# include <ctime>

class Base
{
	private:

	protected:

	public:
		virtual ~Base();
		static Base*		generate(void);
		static void 		identify(Base* p);
		static void			identify(Base& p);
};

# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

#endif
