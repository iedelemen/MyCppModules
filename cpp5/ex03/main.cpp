#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	try {
		Intern someRandomIntern;
		Bureaucrat boss("Boss", 1);

		AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "garden");
		AForm* form2 = someRandomIntern.makeForm("robotomy request", "Wall-E");
		AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Trillian");

		someRandomIntern.makeForm("nonexistent form", "nonexistent target");

		boss.signForm(*form1);
		boss.executeForm(*form1);

		boss.signForm(*form2);
		boss.executeForm(*form2);

		boss.signForm(*form3);
		boss.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;

	}catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
