#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragTrap")
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\033[94mFragTrap ordusundan "<< _name << ": Merhabalar!\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\033[94mFragTrap ordusundan " << _name << ": Merhabalar!\033[0m" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "\033[94mKopya " << "FragTrap ordusundan " << _name << ": MERHABALAR!\033[0m" << std::endl;
	*this = obj;
}

FragTrap::~FragTrap()
{
	std::cout << "\033[94mFragTrap ordusundan " << _name << ": Ben kaçar!\033[0m" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		_name = obj._name;
		_hitPoints = obj._hitPoints;
		_energyPoints = obj._energyPoints;
		_attackDamage = obj._attackDamage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "\033[94mFragTrap ordusundan " << _name << ": Çak!\033[0m" << std::endl;
}
