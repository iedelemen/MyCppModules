#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), _target(obj._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}

string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getSigned())
	{
		cout << "Form is not signed" << endl;
		return ;
	}
	cout << "SOME DRILLING NOISES" << endl;
	srand(time(NULL));
	if (rand() % 2)
		cout << _target << " has been robotomized successfully" << endl;
	else
		cout << _target << " robotomization has failed" << endl;
}

