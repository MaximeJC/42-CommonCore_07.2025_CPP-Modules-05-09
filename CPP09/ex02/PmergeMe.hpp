#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip>
#include <string>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <cmath>

class PmergeMe {
private:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &rhs);
	~PmergeMe();

	static int Jacobsthal(int n);
	static void FordJohnsonInsert(std::vector<int> &main, std::vector<int> &pend, int odd_value, std::vector<int> &non_participant, std::vector<int> &vec, bool is_odd, int pair_size);
	static void FordJohnsonInsert(std::deque<int> &main, std::deque<int> &pend, int odd_value, std::deque<int> &non_participant, std::deque<int> &deq, bool is_odd, int pair_size);

public:
	static void FordJohnsonSort(std::vector<int> &vec);
	static void FordJohnsonSort(std::deque<int> &deq);
};

#endif
