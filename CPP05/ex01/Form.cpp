#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _signGrade(_lowestGrade), _executeGrade(_lowestGrade) {}

Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	if (signGrade < _highestGrade || executeGrade < _highestGrade) {
		throw GradeTooHighException();
	} else if (signGrade > _lowestGrade || executeGrade > _lowestGrade) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	if (_isSigned) {
		throw FormAlreadySigned();
	}
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* Form::FormAlreadySigned::what() const throw() {
	return "Form is already signed!";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
	os << "Form name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Sign grade: " << form.getSignGrade() << ", Execution grade: " << form.getExecuteGrade();
	return os;
}
