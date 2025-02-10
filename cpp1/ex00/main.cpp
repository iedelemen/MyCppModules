#include "Zombie.hpp"

int main(int arc, char **arv)
{
	{
		if (arc < 2)
			return 0;
		Zombie zombie(arv[1]);
		zombie.announce();
	}
	{
		if (arc < 3)
			return 0;
		Zombie *zombie = newZombie(arv[2]);
		delete zombie;
	}
	{
		if (arc < 4)
			return 0;
		randomChump(arv[3]);
	}
}
