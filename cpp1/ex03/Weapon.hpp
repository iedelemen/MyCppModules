#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
using std::string;

class Weapon
{
	private:
		string _type;

	public:
		Weapon(string type);
		~Weapon();
		const string &getType();
		void setType(string type);
};



# endif
