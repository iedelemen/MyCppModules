#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
using std::string;
using std::cout;
using std::endl;

class Intern
{
	private:
		string _names[3];
		AForm* (Intern::*_functions[3])(string target);
		AForm* createShrubberyCreationForm(string target);
		AForm* createRobotomyRequestForm(string target);
		AForm* createPresidentialPardonForm(string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator = (const Intern& obj);

		AForm* makeForm(string name, string target);
};

#endif

