#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\033[92mScavTrap ordusundan " << "ScavTrap ordusundan " << _name << ": Merhabalar!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\033[92mScavTrap ordusundan " << _name << ": Merhabalar!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "\033[92mKopya " << "ScavTrap ordusundan " << _name << ": MERHABALAR!\033[0m" << std::endl;
	*this = obj;
}

ScavTrap::~ScavTrap()
{
	std::cout << "\033[92mScavTrap ordusundan " << _name << ": Ben kaçar!\033[0m" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
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

void ScavTrap::attack(std::string const &target)
{
	if (_energyPoints > 0)
	{
		std::cout << "\033[92mScavTrap ordusundan " << _name << " " << target << " adlı hedefe " << _attackDamage << " hasar verdi!\033[0m" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "\033[92mScavTrap ordusundan " << _name << ": Enerjim bitti!\033[0m" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "\033[92mScavTrap ordusundan " << _name << ": Kapıyı koruyorum!\033[0m" << std::endl;
}
