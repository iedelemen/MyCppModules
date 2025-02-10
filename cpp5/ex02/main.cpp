#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 1);
		Bureaucrat intern("Intern", 140);

		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Alice");

		intern.signForm(shrubbery);
		bob.executeForm(shrubbery);

		intern.signForm(robotomy);
		bob.executeForm(robotomy);

		bob.signForm(pardon);
		bob.executeForm(pardon);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

