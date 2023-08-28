#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iostream>
# include <vector>
# include <ctime>
# include <deque>
# include <algorithm>
# include <exception>

# ifndef CLASS
// #  define CLASS(x, y) std::cout << ""
#  define CLASS(x, y) std::cout << "Called " << x << " of class " << y << std::endl
# endif

template<typename T>
	class Iter
{
	public:
	typename T::iterator		_Start;
	typename T::iterator		_End;
	typename T::iterator		_PrevOfEnd;
	typename T::iterator		_NextOfEnd;
};

class PmergeMe
{
	private:
		std::vector<int>								Vnumbers;

		std::vector<int>::iterator	 					Vmain_it;
		std::vector<int>::iterator 						Vmain_ite;
		std::vector<int>::iterator 						Vmain_ite_plus_one;
		std::vector<int>::iterator 						Vmain_ite_minus_one;

		std::vector<std::pair<int, int> >				V;
		std::vector<std::pair<int, int> >::iterator		Vit;
		std::vector<std::pair<int, int> >::iterator		Vite;

		std::vector<std::pair<int, int> > 				Vmap;	
		std::vector<std::pair<int, int> >::iterator 	Vmap_it;
		std::vector<std::pair<int, int> >::iterator 	Vmap_ite;

		int												Vimpair;

		void											Vmain();
		void											VcreatePairs();
		void											VsortPairs();
		void											VinsertByFirst();
		void											VinsertmergeSeconds();

		
		
		
		std::deque<int>									Lnumbers;

		std::deque<int>::iterator	 					Lmain_it;
		std::deque<int>::iterator 						Lmain_ite;
		std::deque<int>::iterator 						Lmain_ite_plus_one;
		std::deque<int>::iterator 						Lmain_ite_minus_one;

		std::deque<std::pair<int, int> >					L;
		std::deque<std::pair<int, int> >::iterator		Lit;
		std::deque<std::pair<int, int> >::iterator		Lite;

		std::deque<std::pair<int, int> > 				Lmap;	
		std::deque<std::pair<int, int> >::iterator 		Lmap_it;
		std::deque<std::pair<int, int> >::iterator 		Lmap_ite;

		int												Limpair;

		void											Lmain();
		void											LcreatePairs();
		void											LsortPairs();
		void											LinsertByFirst();
		void											LinsertmergeSeconds();
	protected:

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe&);
		PmergeMe& operator= (const PmergeMe&);
		void	VSortMergeAlgo(char **, int);


		void	LSortMergeAlgo(char **, int);


		class Doubles: public std::exception
		{
			const char* what() const throw();
		};
};

void	Vprint_main(std::vector<int> v);
void	Lprint_main(std::deque<int> v);
void	Vprint(std::vector<std::pair<int, int> > v);


#endif
