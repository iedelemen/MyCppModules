#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

using std::string;

class HumanB
{
	private:
		Weapon* _weapon;
		string _name;
	public:
		HumanB(string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif
