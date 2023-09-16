#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <list>
# include <climits>
# ifndef CLASS
#  define CLASS(x, y) std::cout << ""
// #  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class RPN
{
	private:
		std::list<int>					_Numbers;

		void		ListInit(std::list<std::string> lst);
		void		_FtCalcul(std::string s);
	protected:

	public:
		RPN();
		~RPN();
		RPN(const RPN&);
		RPN& operator= (const RPN&);
		void		_RPNCalculation(std::list<std::string> lst);
		
		class Empty: public std::exception
		{
			const char* what() const throw();
		};
		class BadArg: public std::exception
		{
			const char* what() const throw();
		};
		class BadOp: public std::exception
		{
			const char* what() const throw();
		};
		class InputNotFormatedWell: public std::exception
		{
			const char* what() const throw();
		};
		class MissingOperators: public std::exception
		{
			const char* what() const throw();
		};
		class OutOfRange: public std::exception
		{
			const char* what() const throw();
		};
		class DivisionByZero: public std::exception
		{
			const char* what() const throw();
		};
};

int	my_atoi(const char *s);
bool	is_operator(std::string s);

#endif
