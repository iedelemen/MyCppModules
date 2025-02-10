#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[38;5;129mClapTrap ordusundan " <<_name << ": Merhabalar!\033[0m" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "\033[38;5;129mClapTrap ordusundan " <<_name << ": Merhabalar!\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : _name(obj._name), _hitPoints(obj._hitPoints), _energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage)
{
	std::cout << "\033[38;5;129mClapTrap ordusundan " << "Kopya " << _name << ": MERHABALAR!\033[0m" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\033[38;5;129mClapTrap ordusundan " << _name << ": Ben kaçar!\033[0m" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
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

void ClapTrap::attack(std::string const& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << "\033[38;5;129mClapTrap ordusundan " << _name  << " " << target << " adlı hedefe " << _attackDamage << " hasar verdi!\033[0m" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "\033[38;5;129mClapTrap ordusundan " << _name << ": zaten ölü!\033[0m" << std::endl;
	else
		std::cout << "\033[38;5;129mClapTrap ordusundan " << _name << ": Enerjim bitti!\033[0m" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "\033[38;5;129mClapTrap ordusundan " << _name << ": " << amount << " hasar aldım!\033[0m" << std::endl;
	}
	else
		std::cout << "\033[38;5;129mClapTrap ordusundan " << _name << ": Ben zaten ölüyüm!\033[0m" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "\033[38;5;129mClapTrap ordusundan " << _name << ": " << amount << " kadar iyileştim!\033[0m" << std::endl;
	}
	else
		std::cout << "\033[38;5;129mClapTrap ordusundan " << _name << ": Ben zaten ölüyüm!\033[0m" << std::endl;
}

std::string ClapTrap::getName()
{
	return _name;
}

int ClapTrap::getHitPoints()
{
	return _hitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return _energyPoints;
}

int ClapTrap::getAttackDamage()
{
	return _attackDamage;
}

