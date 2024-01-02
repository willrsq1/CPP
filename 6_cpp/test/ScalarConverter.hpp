#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
#include <iomanip>
# ifndef CLASS
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

class ScalarConverter
{
    private:

    static bool isChar(const std::string &input);
    static bool isInt(const std::string &input);
    static bool isFloat(const std::string &input);
    static bool isDouble(const std::string &input);

    static void convertChar(const std::string &input);
    static void convertInt(const std::string &input);
    static void convertFloat(const std::string &input);
    static void convertDouble(const std::string &input);


    public:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator= (const ScalarConverter&);
        
        static void convert(const std::string& input);

};

#endif