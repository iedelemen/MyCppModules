#include "Zombie.hpp"

int main(int arc, char **arv)
{
	(void)arv;
	if (arc != 1)
		return std::cout << "Do not enter any argument!!" << std::endl, 0;
	string name;
	string c_count;
	int count = 0;
	do {
	std::cout << "\33cEnter whatever you want the zombie's name = ";
	std::getline(std::cin, name);
	}while (name.empty());
	std::cout << "Enter how many zombies do you want = ";
	std::getline(std::cin, c_count);
	count = std::atoi(c_count.c_str());
	if (count <= 0 || count > INT_MAX)
		return std::cout << "Invalid argument" << std::endl, 0;
	Zombie *walkingDead;
	walkingDead = zombieHorde(count, name);
	for (int i = 0; i < count; i++)
		walkingDead[i].announce();
	delete[] walkingDead;
}
