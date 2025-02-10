#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), _target(obj._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}

string PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw AForm::GradeTooLowException();
	if (!getSigned())
	{
		cout << "Form is not signed" << endl;
		return ;
	}
	cout << _target << " has been pardoned by Zafod Beeblebrox" << endl;
}


