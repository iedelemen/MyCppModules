#include "Cat.hpp"

Cat::Cat() {
	cout << "Cat constructor called" << endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& obj) {
	cout << "Cat copy constructor called" << endl;
	this->_brain = new Brain(*obj._brain);
}

Cat::~Cat() {
	cout << "Cat destructor called" << endl;
	delete _brain;
}

Cat& Cat::operator=(const Cat& obj) {
	cout << "Cat assignation operator called" << endl;
	if (this != &obj)
	{
		delete _brain;
		_brain = new Brain(*obj.getBrain());
	}
	Animal::operator=(obj);
	return *this;
}
const string& Cat::getType() const {
	return _type;
}

void Cat::makeSound() const {
	cout << "Miyav" << endl;
}

Brain* Cat::getBrain()const {
	return _brain;
}
