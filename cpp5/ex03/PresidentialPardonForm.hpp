#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"
using std::string;
using std::cout;
using std::endl;

class PresidentialPardonForm : public AForm
{
	private:
		const string _target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(const string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator = (const PresidentialPardonForm& obj);

		string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};

#endif
