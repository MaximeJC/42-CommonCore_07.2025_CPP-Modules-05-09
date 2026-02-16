#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*forms[])(const std::string&) = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			AForm* form = (*forms[i])(target);
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return form;
		}
	}
	throw UnknownFormException();
}

const char* Intern::UnknownFormException::what() const throw() {
	return "Unknown form type.";
}

std::ostream& operator<<(std::ostream& os, const Intern& intern) {
	(void)intern;
	os << "Intern: Do you want a coffee Master ?";
	return os;
}

AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}
