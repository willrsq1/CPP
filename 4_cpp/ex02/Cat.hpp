#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"

class Cat: public AAnimal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat&);
		Cat& operator= (const Cat&);
		void	makeSound() const;
		std::string		getType() const;
		void	ShowBrainIdea(int n);
};

#endif