#include "Dog.hpp"

Dog::Dog() {
	cout << "Dog constructor called" << endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& obj) {
	cout << "Dog copy constructor called" << endl;
	_brain = new Brain(*obj._brain);
}

Dog::~Dog() {
	cout << "Dog destructor called" << endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog& obj) {
	cout << "Dog assignation operator called" << endl;
	if (this != &obj)
	{
		delete _brain;
		_type = obj.getType();
		_brain = new Brain(*obj.getBrain());
	}
	return *this;
}

const string& Dog::getType() const {
	return _type;
}

void Dog::makeSound() const {
	cout << "Hav Hav" << endl;
}

Brain* Dog::getBrain() const {
	return _brain;
}

