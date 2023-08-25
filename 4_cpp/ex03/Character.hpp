#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

typedef	struct	s_Unequiped_Materia t_Unequiped_Materia;

typedef	struct	s_Unequiped_Materia
{
	AMateria*				_ptrMateria;
	t_Unequiped_Materia		*next;
}	t_Unequiped_Materia;


class Character: public ICharacter
{
	private:
		void 	newMateria(AMateria*);
		void	setNull();
		void	deleteMaterias();
		std::string				_Name;
		AMateria*				_Tab[MATERIA_TAB_SIZE];
		t_Unequiped_Materia*	_List;	
	public:
		Character();
		Character(std::string);
		~Character();
		Character(const Character&);
		Character& operator= (const Character&);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int);
		void use(int idx, ICharacter& target);
};

#endif
