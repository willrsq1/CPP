#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

	template<typename T>
class Array
{
	private:
		T*				_Tab;
		unsigned int*	_Size;
	protected:

	public:
		Array();
		Array(unsigned int);
		~Array();
		Array(const Array&);
		Array& operator= (const Array&);
		T& operator[] (int i)
		{
			if (i < 0 || i >= (int)*this->_Size)
				throw std::exception();
			return (this->_Tab[i]);
		}
		unsigned int	getSize() const{
			return (*this->_Size);
		}
};

# include "Array.tpp"

#endif
