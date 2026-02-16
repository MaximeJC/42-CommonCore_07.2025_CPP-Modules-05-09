#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat bureaucrat1("Alice", 42);
	std::cout << bureaucrat1 << std::endl;

	//* Successful cases

	std::cout << ">> Signable form:" << std::endl;
	try {
		Form form1("Form1", 50, 100);
		std::cout << form1 << std::endl;
		bureaucrat1.signForm(form1);
		std::cout << form1 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	Form form2("Form2", 42, 100);
	std::cout << form2 << std::endl;
	bureaucrat1.signForm(form2);
	std::cout << form2 << std::endl;

	//! Failing cases

	std::cout << std::endl << ">> Trying to sign form already signed:" << std::endl;
	bureaucrat1.signForm(form2);
	std::cout << form2 << std::endl;

	std::cout << std::endl << ">> Trying to create form with 0 and 151 grades:" << std::endl;
	try {
		Form form3("Form3", 0, 100);
		std::cout << form3 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Form form4("Form4", 50, 151);
		std::cout << form4 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl << ">> Trying to sign a form with too low grade:" << std::endl;
	Form form5("Form5", 25, 100);
	std::cout << form5 << std::endl;
	bureaucrat1.signForm(form5);
	std::cout << form5 << std::endl;

	return 0;
}
