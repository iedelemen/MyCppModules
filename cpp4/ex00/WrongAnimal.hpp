#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
using std::string;
using std::cout;
using std::endl;

class WrongAnimal
{
	protected:
		string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		WrongAnimal& operator=(const WrongAnimal& obj);
		~WrongAnimal();
		const string& getType() const;
		void makeSound() const;
};


# endif
