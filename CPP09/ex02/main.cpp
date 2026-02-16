#include "PmergeMe.hpp"

int checkArgs(int argc, char const *argv[])
{
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++) {
			if (!isdigit(arg[j])) {
				std::cerr << "Error: Invalid argument '" << arg << "'" << std::endl;
				return 1;
			}
		}
		long num = std::atol(argv[i]);
		if (num < 0 || num > INT_MAX) {
			std::cerr << "Error: Argument out of range '" << argv[i] << "'" << std::endl;
			return 1;
		}
	}
	return 0;
}

int checkDoubles(const std::vector<int> &vec)
{
	std::vector<int> temp = vec;
	std::sort(temp.begin(), temp.end());
	for (size_t i = 1; i < temp.size(); i++) {
		if (temp[i] == temp[i - 1]) {
			std::cerr << "Error: Duplicate number '" << temp[i] << "'" << std::endl;
			return 1;
		}
	}
	return 0;
}

template <typename Container>
void printContainer(Container &container)
{
	for (size_t i = 0; i < container.size(); i++) {
		std::cout << container[i];
		if (i < container.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	if (argc < 3) {
		std::cerr << "Usage: ./PmergeMe 51 42 35 88 [...]" << std::endl;
		std::cerr << "Note: One number is not enough to perform a sort" << std::endl;
		return 1;
	}
	if (checkArgs(argc, argv))
		return 1;

	std::vector<int> vec;
	std::deque<int> deq;
	for (int i = 1; i < argc; i++) {
		int num = std::atoi(argv[i]);
		vec.push_back(num);
		deq.push_back(num);
	}
	if (checkDoubles(vec))
		return 1;

	std::cout << "Before: ";
	printContainer(vec);

	struct timeval vecBefore, vecAfter, deqBefore, deqAfter;

	gettimeofday(&vecBefore, NULL);
	PmergeMe::FordJohnsonSort(vec);
	gettimeofday(&vecAfter, NULL);

	gettimeofday(&deqBefore, NULL);
	PmergeMe::FordJohnsonSort(deq);
	gettimeofday(&deqAfter, NULL);

	std::cout << "After (vector): ";
	printContainer(vec);
	// std::cout << "After (deque) : ";
	// printContainer(deq);

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(3)
		<< static_cast<double>((vecAfter.tv_sec - vecBefore.tv_sec) * 1000000 + (vecAfter.tv_usec - vecBefore.tv_usec)) / 1000 << " milliseconds" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed << std::setprecision(3)
		<< static_cast<double>((deqAfter.tv_sec - deqBefore.tv_sec) * 1000000 + (deqAfter.tv_usec - deqBefore.tv_usec)) / 1000 << " milliseconds" << std::endl;
	return 0;
}

