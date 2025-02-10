#include "Intern.hpp"

Intern::Intern()
{
	_names[0] = "shrubbery creation";
	_names[1] = "robotomy request";
	_names[2] = "presidential pardon";
	_functions[0] = &Intern::createShrubberyCreationForm;
	_functions[1] = &Intern::createRobotomyRequestForm;
	_functions[2] = &Intern::createPresidentialPardonForm;
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}

Intern& Intern::operator = (const Intern& obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

AForm* Intern::makeForm(string name, string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (name == _names[i])
			return (this->*_functions[i])(target);
	}
	cout << "Form not found" << endl;
	return NULL;
}

AForm* Intern::createShrubberyCreationForm(string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(string target)
{
	return new PresidentialPardonForm(target);
}

