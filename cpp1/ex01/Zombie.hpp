#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::string;

class Zombie
{
	private:
		string _name;
	public:
		Zombie();
		~Zombie();
		void setName(string name);
		void announce(void);
};

Zombie* zombieHorde(int N , string name);

# endif
