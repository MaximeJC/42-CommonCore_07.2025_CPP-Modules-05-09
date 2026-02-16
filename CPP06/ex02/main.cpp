#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

Base* generate() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int randNum = std::rand() % 3;
	switch (randNum) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Unknown type" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown type" << std::endl;
}

int main() {
	Base* basePtr = generate();
	if (!basePtr) {
		std::cerr << "Failed to generate a Base object." << std::endl;
		return 1;
	}
	std::cout << "Identifying using pointer:" << std::endl;
	identify(basePtr);
	std::cout << "Identifying using reference:" << std::endl;
	identify(*basePtr);
	delete basePtr;
	return 0;
}
