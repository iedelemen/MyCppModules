#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	_signed = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm& obj) : _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
}

AForm& AForm::operator = (const AForm& obj)
{
	if (this == &obj)
		return *this;
	_signed = obj._signed;
	return *this;
}

string AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator << (std::ostream& out, const AForm& obj)
{
	out << obj.getName() << " form is ";
	if (obj.getSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << obj.getSignGrade() << " to sign and grade " << obj.getExecGrade() << " to execute";
	return out;
}

