#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", this->_signGrade, this->_executeGrade), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", this->_signGrade, this->_executeGrade), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned()) {
		throw AForm::FormNotSignedYet();
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form) {
	os << "Presidential pardon form name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Sign grade: " << form.getSignGrade() << ", Execution grade: " << form.getExecuteGrade()
	   << ", Target: " << form.getTarget();
	return os;
}
