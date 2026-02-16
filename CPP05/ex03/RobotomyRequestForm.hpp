#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
	static const int _signGrade = 72;
	static const int _executeGrade = 45;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	std::string getTarget() const;

	void execute(const Bureaucrat& executor) const;
};
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form);

#endif
