#ifndef AFROM_HPP
#define AFROM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
using std::string;
using std::cout;
using std::endl;

class AForm
{
	private:
		const string _name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;
	public:
		AForm();
		virtual ~AForm();
		AForm(const string name, int signGrade, int execGrade);
		AForm(const AForm& obj);
		AForm& operator = (const AForm& obj);

		string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;

		void beSigned(Bureaucrat& obj);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator << (std::ostream& out, const AForm& obj);

#endif
