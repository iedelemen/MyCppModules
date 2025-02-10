#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
using std::string;
using std::cout;
using std::endl;

class AForm;
class Bureaucrat
{
	private:
		const string _name;
		int _grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const string name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator = (const Bureaucrat& obj);

		string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form);
		void executeForm(AForm const & form) const;

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
std::ostream& operator << (std::ostream& out, const Bureaucrat& obj);


#endif
