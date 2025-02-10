#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << _name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << name << " became a zombie" << std::endl;
	_name = name;
}
Zombie::~Zombie()
{
	std::cout << _name << " is dead" << std::endl;
}
