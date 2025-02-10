#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
using std::string;
using std::cout;
using std::endl;

class RobotomyRequestForm : public AForm
{
	private:
		const string _target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(const string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator = (const RobotomyRequestForm& obj);

		string getTarget() const;

		void execute(Bureaucrat const & executor) const;
};

#endif
