#ifndef AMETARIA_HPP
# define AMETARIA_HPP

# include <iostream>
# ifndef CLASS(x, y)
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class AMetaria
{
	private:

	protected:

	public:
		AMetaria();
		~AMetaria();
		AMetaria(const AMetaria&);
		AMetaria& operator= (const AMetaria&);
};

#endif
