#include "Span.hpp"
#include <ctime>

int main()
{
	std::cout << "-----=={Subject tests}==-----" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << "-----=={Additional tests}==-----" << std::endl;
	Span sp2 = Span(10000);
	std::vector<int> vec;
	for (int i = 0; i < 10000; ++i) {
		srand(time(NULL) + -7 * i);
		vec.push_back(rand() % 100000);
	}
	sp2.addNumber(vec.begin(), vec.end());
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;

	std::cout << "-----=={Exceptions tests}==-----" << std::endl;
	Span sp3 = Span(3);
	sp3.addNumber(1);
	try {
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp3.addNumber(2);
		sp3.addNumber(3);
		sp3.addNumber(4);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

