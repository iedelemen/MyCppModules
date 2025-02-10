#include "Cat.hpp"

Cat::Cat() {
	cout << "Cat constructor called" << endl;
	_type = "Cat";
}

Cat::Cat(const Cat& obj) {
	cout << "Cat copy constructor called" << endl;
	*this = obj;
}

Cat::~Cat() {
	cout << "Cat destructor called" << endl;
}

Cat& Cat::operator=(const Cat& obj) {
	cout << "Cat assignation operator called" << endl;
	Animal::operator=(obj);
	return *this;
}
const string& Cat::getType() const {
	return _type;
}

void Cat::makeSound() const {
	cout << "Miyav" << endl;
}
