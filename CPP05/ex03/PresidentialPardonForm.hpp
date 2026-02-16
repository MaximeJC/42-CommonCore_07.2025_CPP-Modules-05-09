#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string _target;
	static const int _signGrade = 25;
	static const int _executeGrade = 5;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	std::string getTarget() const;

	void execute(const Bureaucrat& executor) const;
};
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form);

#endif
