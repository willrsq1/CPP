#include "Zombie.hpp"

int	main()
{
	Zombie	zomb_one("Paul");
	Zombie	*zomb_hord;
	int		i = 0;
	int		N;

	N = 10;
	std::cout << "Creating a zombie horde of " << N << " zombies." << std::endl;
	zomb_one.announce();
	zomb_hord = zombieHorde(N, "Luffy");
	while (i < N)
	{
		zomb_hord->announce();
		i++;
	}
	delete[] zomb_hord;
	return (0);
}