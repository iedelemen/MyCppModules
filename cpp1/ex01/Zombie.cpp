#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(string name)
{
	_name = name;
}

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}
