#include "ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("Mehmet");
	ClapTrap claptrap2("Ahmet");
	claptrap.attack("Ahmet");
	claptrap2.takeDamage(0);
	claptrap2.beRepaired(0);

	return 0;
}
