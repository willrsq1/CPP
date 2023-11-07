#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <climits>
# include <fstream>
# ifndef CLASS
#  define CLASS(x, y) std::cout << ""
// #  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class BitcoinExchange
{
	private:
		std::map<int, float>		_Map;


		void			GetInitData();
		void			GetFileData(std::string filename);
		void			DisplayValue(std::string);
	protected:

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator= (const BitcoinExchange&);
		void			ft_BtcEx(std::string);
		bool			checkDateError(const std::string &date);
		bool			isLeapYear(unsigned int year);
		float	 		my_number_atoi(const char *s);
		float	 		my_input_number_atoi(const char *s);
		int	 			my_input_key_atoi(const char *s);
		int	 			my_key_atoi(const char *s);
		
		class BadOpen: public std::exception
		{
			const char* what() const throw();
		};
		class EmptyArg: public std::exception
		{
			const char* what() const throw();
		};
		class BadArg: public std::exception
		{
			const char* what() const throw();
		};
		class BadFirstLine: public std::exception
		{
			const char* what() const throw();
		};
		class NotPositiveInt: public std::exception
		{
			const char* what() const throw();
		};

};

int		my_key_atoi(const char *s);
float	my_number_atoi(const char *s);
int	my_input_key_atoi(const char *s);
float	my_input_number_atoi(const char *s);

#endif
