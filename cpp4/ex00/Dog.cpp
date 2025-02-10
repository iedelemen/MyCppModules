#include "Dog.hpp"

Dog::Dog() {
	cout << "Dog constructor called" << endl;
	_type = "Dog";
}

Dog::Dog(const Dog& obj) {
	cout << "Dog copy constructor called" << endl;
	*this = obj;
}

Dog::~Dog() {
	cout << "Dog destructor called" << endl;
}

Dog& Dog::operator=(const Dog& obj) {
	cout << "Dog assignation operator called" << endl;
	if (this != &obj)
		_type = obj.getType();
	return *this;
}

const string& Dog::getType() const {
	return _type;
}

void Dog::makeSound() const {
	cout << "Hav Hav" << endl;
}

