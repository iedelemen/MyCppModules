#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("Celal");
	ClapTrap clap1("Ahmet");
	clap.attack("Ahmet");
	clap1.takeDamage(5);
	clap1.beRepaired(3);
	std::cout << "-------------------------------------" << std::endl;
	FragTrap frag("Faruk");
	FragTrap frag1("Mehmet");
	frag.attack("Mehmet");
	frag1.takeDamage(20);
	frag1.beRepaired(10);
	frag.highFivesGuys();

	return 0;
}
