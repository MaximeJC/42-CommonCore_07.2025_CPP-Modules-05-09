#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	std::cout << "-----=={Vector}==-----" << std::endl;
	std::vector<int> vec;
	for (int i = 0; i < 5; ++i) {
		vec.push_back(i + 1);
	}
	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	try {
		std::vector<int>::iterator it = easyFind(vec, 2);
		std::cout << "Found: " << *it << std::endl;
		it = easyFind(vec, 8);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "-----=={List}==-----" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 5; i++) {
		lst.push_back(i * 10);
	}
	std::cout << "List: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	try {
		std::list<int>::iterator it = easyFind(lst, 20);
		std::cout << "Found: " << *it << std::endl;
		it = easyFind(lst, 42);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
}
