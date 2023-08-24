#include "DiamondTrap.hpp"

int	main()
{
	//HIT POINT =  100 (frag)
	//ENERGY POINT = 50 scav
	//ATACK DMG = 30 frag
	DiamondTrap d("paul");

	d.beRepaired(0);
	d.attack("Jack");
	std::cout << d.get_EP() << std::endl;
	int i = 5;
	while (i--)
		d.beRepaired(0);
	d.whoAmI();
	d.highFivesGuys();
	d.guardGate();
	d.show_Attack_Damage();
	d.show_Energy_Points();
	d.show_Hit_Points();
}