#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
using std::string;
using std::cout;
using std::endl;

class Animal
{
	protected:
		string _type;
	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator=(const Animal& obj);
		virtual ~Animal();
		const string& getType() const;
		virtual void makeSound() const;
};


# endif
