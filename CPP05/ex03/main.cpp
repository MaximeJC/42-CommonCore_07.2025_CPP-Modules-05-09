#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << ">> Intern creation:" << std::endl;
	Intern dobby;
	std::cout << dobby << std::endl;

	std::cout << std::endl << ">> Form creation by intern:" << std::endl;
	try {
		AForm* form1 = dobby.makeForm("shrubbery creation", "Home");
		std::cout << *form1 << std::endl;
		AForm* form2 = dobby.makeForm("robotomy request", "R2D2");
		std::cout << *form2 << std::endl;
		AForm* form3 = dobby.makeForm("presidential pardon", "John Smith");
		std::cout << *form3 << std::endl;
		delete form1;
		delete form2;
		delete form3;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << ">> Unknown form creation by intern:" << std::endl;

	try {
		AForm* unknownForm = dobby.makeForm("commoncore fast finish", "Me");
		std::cout << *unknownForm << std::endl;
		delete unknownForm;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
