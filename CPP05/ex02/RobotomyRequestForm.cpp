#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", this->_signGrade, this->_executeGrade), _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", this->_signGrade, this->_executeGrade), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned()) {
		throw AForm::FormNotSignedYet();
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::GradeTooLowException();
	}
	if (rand() % 2) {
		std::cout << "* Some drilling noises * " << this->_target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "* Some drilling noises * " << this->_target << " robotomy failed." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form) {
	os << "Robotomy request form name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Sign grade: " << form.getSignGrade() << ", Execution grade: " << form.getExecuteGrade()
	   << ", Target: " << form.getTarget();
	return os;
}
