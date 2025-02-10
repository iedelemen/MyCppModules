#include "Weapon.hpp"

Weapon::Weapon(string type):_type(type){}
Weapon::~Weapon(){}

const string& Weapon::getType()
{
	return _type;
}

void Weapon::setType(string type)
{
	_type = type;
}
