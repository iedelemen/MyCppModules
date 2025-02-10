#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		cout << "---------------------------\n"
			 << endl;
		Dog Kangal;
		Cat VanKedisi;
		Kangal.makeSound();
		VanKedisi.makeSound();
	}
	{
		cout << "\n---------------------------\n"
			 << endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		cout << "\n---------------------------\n"
			 << endl;
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound();
		delete meta;
		delete i;
	}
}
