#include "HumanB.hpp"

HumanB::HumanB(string name): _weapon(0), _name(name){}
HumanB::~HumanB(){};

void HumanB::attack()
{
	if (_weapon != NULL)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " doesn't want to attack" << std::endl;
}
void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
