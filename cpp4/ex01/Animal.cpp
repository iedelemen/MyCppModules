#include "Animal.hpp"

Animal::Animal() {
	cout << "Animal constuctor called" << endl;
	_type = "Animal";
}

Animal::Animal(const Animal& obj) {
	cout << "Animal copy constuctor called" << endl;
	*this = obj;
}

Animal::~Animal() {
	cout << "Animal destructor called" << endl;
}

Animal& Animal::operator=(const Animal& obj) {
	cout << "Animal assignation operator called" << endl;
	if (this != &obj)
		_type = obj.getType();
	return *this;
}

const string& Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	cout << "Animal sound" << endl;
}
