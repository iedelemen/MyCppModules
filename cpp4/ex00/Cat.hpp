#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& obj);
		Cat& operator=(const Cat& obj);
		~Cat();
		const string& getType() const;
		void makeSound() const;
};



# endif
