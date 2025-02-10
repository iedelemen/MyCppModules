#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	cout << "WrongAnimal constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	cout << "WrongAnimal copy constructor called" << endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal destructor called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	cout << "WrongAnimal assignation operator called" << endl;
	if (this != &obj)
		_type = obj.getType();
	return *this;
}

const string& WrongAnimal::getType() const {
	return _type;
}

void WrongAnimal::makeSound() const {
	cout << "WrongAnimal sound" << endl;
}
