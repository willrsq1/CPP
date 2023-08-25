#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# ifndef CLASS(x, y)
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class Ice
{
	private:

	protected:

	public:
		Ice();
		~Ice();
		Ice(const Ice&);
		Ice& operator= (const Ice&);
};

#endif
