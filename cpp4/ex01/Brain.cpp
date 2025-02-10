#include "Brain.hpp"

Brain::Brain(){
	cout << "Brain constuctor called" << endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = "i'll think";
}

Brain::Brain(const Brain& obj) {
	cout << "Brain copy constuctor called" << endl;
	*this = obj;
}

Brain::~Brain() {
	cout << "Brain destructor called" << endl;
}


Brain& Brain::operator=(const Brain& obj) {
	cout << "Brain assignation operator called" << endl;
	if (this != &obj) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = obj._ideas[i];
	}
	return *this;
}

void Brain::setIdea(string idea) {
	for (int i = 0; i < 100; i++)
		_ideas[i] = idea;
}

