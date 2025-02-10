#include "Zombie.hpp"

Zombie* newZombie(string name)
{
	Zombie* zombie = new Zombie(name);
	zombie->announce();
	return zombie;
}
