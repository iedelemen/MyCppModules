#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::string;

class Zombie
{
	private:
		string _name;
	public:
		Zombie(string name);
		~Zombie();
		void announce(void);
};

	Zombie* newZombie(string name);
	void randomChump(string name);


# endif
