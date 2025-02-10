#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
using std::string;
using std::cout;
using std::endl;

class ShrubberyCreationForm : public AForm
{
	private:
		const string _target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& obj);

		string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};

#endif
