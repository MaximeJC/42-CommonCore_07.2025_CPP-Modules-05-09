#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
	static const int _signGrade = 145;
	static const int _executeGrade = 137;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	std::string getTarget() const;

	void execute(const Bureaucrat& executor) const;
};
std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& form);

#endif
