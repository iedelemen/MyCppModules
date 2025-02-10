#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
using std::string;
using std::cout;
using std::endl;

class Form
{
	private:
		const string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		~Form();
		Form(const string name, int gradeToSign, int gradeToExecute);
		Form(const Form& obj);
		Form& operator = (const Form& obj);

		string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& obj);
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

std::ostream& operator << (std::ostream& out, const Form& obj);

#endif

