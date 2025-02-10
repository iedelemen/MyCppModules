#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade)
{
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& obj)
{
	if (this == &obj)
		return *this;
	_grade = obj._grade;
	return *this;
}

string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream& operator << (std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

void Bureaucrat::signForm(Form& form)
{
	if (form.getSigned())
	{
		cout << _name << " cannot sign " << form.getName() << " because it is already signed" << endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		cout << _name << " signs " << form.getName() << endl;
	}
	catch (std::exception& e)
	{
		cout << _name << " cannot sign " << form.getName() << " because " << e.what() << endl;
	}
}
