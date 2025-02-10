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
		virtual ~Animal() = 0;
		virtual const string& getType() const = 0;
		virtual void makeSound() const = 0;
};

# endif
