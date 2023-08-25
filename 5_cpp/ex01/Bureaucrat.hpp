#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "Form.hpp"

# define RANK_MAX 1
# define RANK_MIN 150
# define UNDEFINED -42
# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif
# define RED	"\033[1;31m"
# define RESET_COLOR "\033[0m"
# define GREEN	"\033[1;32m"

class Form;

class Bureaucrat
{
	private:
		const std::string			_Name;
		int					_Rank;
		void				changeRank(int);
	protected:

	public:
		Bureaucrat();
		Bureaucrat(std::string, int);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat&);
		Bureaucrat& operator= (const Bureaucrat&);
		std::string		getName();
		void			incrGrade();
		void			decrGrade();
		int				getRank();
		bool			signForm(Form&);

	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};
};

std::ostream& 	operator<<(std::ostream&, Bureaucrat&);

#endif
