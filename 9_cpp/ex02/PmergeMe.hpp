#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iostream>
# include <vector>
# include <ctime>
# include <deque>
# include <algorithm>
# include <exception>
# include <sstream>

# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

# define TEMPLATE 1

// DEFINES IF WE WILL USE YHE TEMPLATE CLASS OR THE CLASS WITH TWO DIFFERENT CONTAINERS IMPLEMANTED MANUALLY

# if TEMPLATE  == 0

# elif TEMPLATE == 1

// WITH TEMPLATE

template <typename Container, typename Pairs>
class PmergeMe
{
	private:
		Container											_numbers;

		typename Container::iterator	 					_numbers_it;
		typename Container::iterator 						_numbers_ite;
		typename Container::iterator 						_numbers_ite_plus_one;
		typename Container::iterator 						_numbers_ite_minus_one;

		Pairs												_setOne;
		typename Pairs::iterator							_setOne_it;
		typename Pairs::iterator							_setOne_ite;

		Pairs 												_setTwo_it;	
		typename Pairs::iterator 							_setTwo_it_it;
		typename Pairs::iterator 							_setTwo_it_ite;

		int													_impair;

		void												_Sort();
		void												_CreateStack(char**, int);
		void												_createPairs();
		void												_sortPairs();
		void												_insertByFirst();
		void												_insertmergeSeconds();
		void												_print_Sort(Container v);


		std::stringstream										out;

	protected:

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator= (const PmergeMe&);
		void	_SortStack(char **, int);
		class Doubles: public std::exception
		{
			const char* what() const throw()
			{
				return ("Hey");
			}
		};
};

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe()
{
    CLASS("Constructor", "PmergeMe");
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::~PmergeMe()
{
    CLASS("Destructor", "PmergeMe");
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>::PmergeMe(const PmergeMe& other)
{
    CLASS("Constructor by copy", "PmergeMe");
    if (this == &other)
        return ;
}

template <typename Container, typename Pairs>
PmergeMe<Container, Pairs>& PmergeMe<Container, Pairs>::operator= (const PmergeMe& other)
{
    CLASS("Operand = Constructor", "PmergeMe");
    if (this == &other)
        return (*this);
    return (*this);
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_SortStack(char **tab, int size)
{
	this->_CreateStack(tab, size);
    this->out << "Before:   ";
    this->_print_Sort(_numbers);
    this->_createPairs();
    this->_sortPairs();
    this->_insertByFirst();
    this->_insertmergeSeconds();
    this->out << "After:    ";
    this->_print_Sort(_numbers);
	std::cout << this->out.str();
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_CreateStack(char **tab, int size)
{
    for (int i = 0; i < size; i++) {
        try {
            int num = std::stoi(tab[i]);
            this->_numbers.push_back(num);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << tab[i] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Argument out of range: " << tab[i] << std::endl;
        }
    }
    
    Container double_check;
    typename Container::iterator __it;
    typename Container::iterator __ite;
    __it = _numbers.begin();
    __ite = _numbers.end();
    while (__it != __ite)
    {
        if (std::find(double_check.begin(), double_check.end(), *__it) != double_check.end())
        {
            std::cerr << "Multiple iterations of the number " << *__it << std::endl;
            throw PmergeMe::Doubles();
        }
        double_check.push_back(*__it);
        __it++;
    }
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_createPairs()
{
    int     a;
    int     b;

    _numbers_it = _numbers.begin();
    _numbers_ite = _numbers.end();
    _numbers_ite_plus_one = ++_numbers.end();
    _numbers_ite_minus_one = --_numbers.end();
    while (_numbers_it != _numbers_ite && _numbers_it != _numbers_ite_minus_one)
    {
        a = *_numbers_it;
        ++_numbers_it;
        b = *_numbers_it;
        _setOne.push_back(std::pair<int, int>(a, b));
        ++_numbers_it;
    }
    this->_impair = 0;
    if (_numbers_it == _numbers_ite_minus_one)
        this->_impair = *(_numbers_ite_minus_one);
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_sortPairs()
{
    _setOne_it = _setOne.begin();
    _setOne_ite = _setOne.end();
    while (_setOne_it != _setOne_ite)
    {
        if ((*_setOne_it).first > (*_setOne_it).second)
            std::swap((*_setOne_it).first, (*_setOne_it).second);
        _setOne_it++;
    }
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_insertByFirst()
{
    typename std::vector<std::pair<int, int> >::iterator _setTwo_it_ite_minus_one;
    
    _setTwo_it.insert(_setTwo_it_it, *_setOne.begin());
    _setOne.erase(_setOne.begin());
    _setOne_it = _setOne.begin();
    _setOne_ite = _setOne.end();
    while (_setOne_it != _setOne_ite)
    {
        _setTwo_it_it = _setTwo_it.begin();
        _setTwo_it_ite = --_setTwo_it.end();
        while (_setTwo_it_ite >= _setTwo_it_it && (*_setOne_it).first < (*(_setTwo_it_ite)).first)
            _setTwo_it_ite--;
        _setTwo_it.insert(++_setTwo_it_ite, *_setOne_it);
        _setOne.erase(_setOne_it);
        _setOne_it = _setOne.begin();
        _setOne_ite = _setOne.end();
    }
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_insertmergeSeconds()
{
    _numbers.clear();
    _setTwo_it_it = _setTwo_it.begin();
    _setTwo_it_ite = _setTwo_it.end();
    while (_setTwo_it_it != _setTwo_it_ite)
    {
        _numbers.push_back((*_setTwo_it_it).first);
        _setTwo_it_it++;
    }
    if (this->_impair)
    {
            _numbers_it = _numbers.begin();
            _numbers_ite = --_numbers.end();
            while (_numbers_ite >= _numbers_it && this->_impair < *(_numbers_ite))
                _numbers_ite--;
            _numbers.insert(++_numbers_ite, this->_impair);
    }
    _setOne_it = _setTwo_it.begin();
    _setOne_ite = _setTwo_it.end();
    while (_setOne_it != _setOne_ite)
    {
            _numbers_it = _numbers.begin();
            _numbers_ite = --_numbers.end();
            while (_numbers_ite >= _numbers_it && (*_setOne_it).second < *(_numbers_ite))
                _numbers_ite--;
            _numbers.insert(++_numbers_ite, (*_setOne_it).second);
        _setOne_it++;
    }
}

template <typename Container, typename Pairs>
void PmergeMe<Container, Pairs>::_print_Sort(Container v)
{
    typename Container::iterator it;
    typename Container::iterator ite;
    it = v.begin();
    ite = v.end();
    while (it != ite)
    {
        this->out << (*it) << ' ';
        it++;
    }
    this->out << '\n';
}
 //END OF TEMPLATE
# endif
#endif
