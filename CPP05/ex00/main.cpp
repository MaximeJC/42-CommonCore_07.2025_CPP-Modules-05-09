#include "Bureaucrat.hpp"

int main(void)
{
	//* Successful cases

	try {
		Bureaucrat bureaucrat1("Alice", 42);
		std::cout << bureaucrat1 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	Bureaucrat bureaucrat1("Alice", 42);
	try
	{
		bureaucrat1.incrementGrade();
		std::cout << bureaucrat1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		bureaucrat1.decrementGrade();
		std::cout << bureaucrat1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	//! Failing cases

	std::cout << ">> Trying to create bureaucrats with 0 and 151 grades:" << std::endl;
	try {
		Bureaucrat bureaucrat2("Gerard", 0);
		std::cout << bureaucrat2 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat3("Roger", 151);
		std::cout << bureaucrat3 << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << ">> Trying to promote a bureaucrat with grade 1:" << std::endl;
	Bureaucrat bureaucrat4("Jean", 1);
	std::cout << bureaucrat4 << std::endl;
	try {
		bureaucrat4.incrementGrade();
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << ">> Trying to demote a bureaucrat with grade 150:" << std::endl;
	Bureaucrat bureaucrat5("Steve", 150);
	std::cout << bureaucrat5 << std::endl;
	try {
		bureaucrat5.decrementGrade();
	} catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
