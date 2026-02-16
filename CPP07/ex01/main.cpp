#include "iter.hpp"

void increment(int &i) {
	i++;
}

void uppercase(std::string &s) {
	for (size_t i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
}

template <typename T> void print(T &x) {
	std::cout << x << std::endl;
}

int main() {
	int intArray[] = {0, 1, 2, 3, 4};
	std::string stringArray[] = {"Hello", "World", "!"};

	std::cout << "-----=={Int array}==-----" << std::endl;
	std::cout << "Before increment:" << std::endl;
	::iter(intArray, 5, &print);
	std::cout << "After increment:" << std::endl;
	::iter(intArray, 5, &increment);
	::iter(intArray, 5, &print);

	std::cout << "-----=={String array}==-----" << std::endl;
	std::cout << "Before upper:" << std::endl;
	::iter(stringArray, 3, &print);
	std::cout << "After upper:" << std::endl;
	::iter(stringArray, 3, &uppercase);
	::iter(stringArray, 3, &print);

	return 0;
}
