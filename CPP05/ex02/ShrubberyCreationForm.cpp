#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", this->_signGrade, this->_executeGrade), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", this->_signGrade, this->_executeGrade), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!this->isSigned()) {
		throw AForm::FormNotSignedYet();
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw AForm::GradeTooLowException();
	}

	std::ofstream output_file;
	output_file.open((const char *)(this->_target + "_shrubbery").c_str());
	if (!output_file) {
		std::cerr << "Error: Could not open file " << this->_target + "_shrubbery" << std::endl;
		return;
	}
	output_file << "\n"
		<< "               ,@@@@@@@,                  \n"
		<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.      \n"
		<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o     \n"
		<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    \n"
		<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    \n"
		<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     \n"
		<< "   `&%\\ ` /%&'    |.|        \\ '|8'       \n"
		<< "       |o|        | |         | |         \n"
		<< "       |.|        | |         | |         \n"
		<< "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_ \n";
	output_file.close();
	std::cout << "Shrubbery has been created at " << this->_target + "_shrubbery" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form) {
	os << "Shrubbery creation form name: " << form.getName() << ", Signed: " << (form.isSigned() ? "Yes" : "No")
	   << ", Sign grade: " << form.getSignGrade() << ", Execution grade: " << form.getExecuteGrade()
	   << ", Target: " << form.getTarget();
	return os;
}
