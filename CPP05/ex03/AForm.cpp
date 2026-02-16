#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(_lowestGrade), _executeGrade(_lowestGrade) {}

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < _highestGrade || executeGrade < _highestGrade) {
		throw GradeTooHighException();
	} else if (signGrade > _lowestGrade || executeGrade > _lowestGrade) {
		throw GradeTooLowException();
	}
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	if (_isSigned) {
		throw FormAlreadySigned();
	}
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::FormAlreadySigned::what() const throw() {
	return "Form is already signed!";
}

const char* AForm::FormNotSignedYet::what() const throw() {
	return "Form is not signed yet!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
	os << "AForm name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Sign grade: " << form.getSignGrade() << ", Execution grade: " << form.getExecuteGrade();
	return os;
}
