#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Cemal");
	ClapTrap clap1("Ahmet");
	clap.attack("Ahmet");
	clap1.takeDamage(0);
	clap1.beRepaired(0);
	std::cout << "-------------------------------------" << std::endl;
	ScavTrap scav("Selim");
	ScavTrap scav1("Veli");
	scav.attack("Veli");
	scav1.takeDamage(20);
	scav1.beRepaired(10);
	scav.guardGate();

	return 0;
}
