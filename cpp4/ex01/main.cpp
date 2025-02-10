#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	{
		cout << "---------------------------\n"
			 << endl;
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	{
		cout << "\n-------------------------\n"
			 << endl;

		const Animal *j = new Dog();
		const Animal *i = new Cat();
		const Dog *y = new Dog();
		const Cat *x = new Cat();
		j->makeSound();
		i->makeSound();
		delete i;
		delete j;
		j = x;
		i = y;
		j->makeSound();
		i->makeSound();
		delete x;
		delete y;
	}
	{
		cout << "\n-------------------------\n"
			 << endl;
		size_t count = 10;
		Animal *animals[count];

		for (size_t i = 0; i < count; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
		for (size_t i = 0; i < count; i++)
			animals[i]->makeSound();
		std::cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
		for (size_t i = 0; i < count; i++)
			delete animals[i];
	}
}
