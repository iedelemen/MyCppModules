#include "WrongCat.hpp"

WrongCat::WrongCat() {
	cout << "WrongCat constructor called" << endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj) {
	cout << "WrongCat copy constructor called" << endl;
	*this = obj;
}

WrongCat::~WrongCat() {
	cout << "WrongCat destructor called" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat& obj) {
	cout << "WrongCat assignation operator called" << endl;
	if (this != &obj)
		_type = obj.getType();
	return *this;
}

const string& WrongCat::getType() const {
	return _type;
}

void WrongCat::makeSound() const {
	cout << "Wrong Miyav" << endl;
}
