#include "Zombie.hpp"

Zombie* zombieHorde(int N, string name)
{
	Zombie *walkingDead = new Zombie[N];
	for (int i = 0; i < N; i++)
		walkingDead[i].setName(name);
	return walkingDead;
}
