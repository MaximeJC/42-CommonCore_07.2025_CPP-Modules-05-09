#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << ">> Employees registration:" << std::endl;
	Bureaucrat president("Alice", 1);
	Bureaucrat middle_employee("Bob", 70);
	Bureaucrat low_employee("Toto", 150);
	std::cout << president << std::endl;
	std::cout << middle_employee << std::endl;
	std::cout << low_employee << std::endl;

	std::cout << std::endl << ">> Forms creation:" << std::endl;
	PresidentialPardonForm presidential_form("John Smith");
	RobotomyRequestForm robotomy_form("Bender");
	ShrubberyCreationForm shrubbery_form("Home");
	std::cout << presidential_form << std::endl;
	std::cout << robotomy_form << std::endl;
	std::cout << shrubbery_form << std::endl;

	std::cout << std::endl << ">> Execute before signing:" << std::endl;
	president.executeForm(presidential_form);
	middle_employee.executeForm(robotomy_form);
	low_employee.executeForm(shrubbery_form);

	std::cout << std::endl << ">> Signing forms:" << std::endl;
	president.signForm(presidential_form);
	middle_employee.signForm(robotomy_form);
	low_employee.signForm(shrubbery_form);
	std::cout << presidential_form << std::endl;
	std::cout << robotomy_form << std::endl;
	std::cout << shrubbery_form << std::endl;
	middle_employee.signForm(shrubbery_form);
	std::cout << shrubbery_form << std::endl;

	std::cout << std::endl << ">> Execute after signing:" << std::endl;
	president.executeForm(presidential_form);
	middle_employee.executeForm(robotomy_form);
	president.executeForm(robotomy_form);
	president.executeForm(robotomy_form);
	president.executeForm(robotomy_form);
	president.executeForm(robotomy_form);
	low_employee.executeForm(shrubbery_form);
	middle_employee.executeForm(shrubbery_form);

	return 0;
}
