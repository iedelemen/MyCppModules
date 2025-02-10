#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

using std::string;

class HumanA
{
	private:
		Weapon& _weapon;
		string _name;
	public:
		HumanA(string name, Weapon &weapon);
		~HumanA();
		void attack();

};

#endif
