#include "PmergeMe.hpp"

// Jacobsthal sequence helps optimize the binary search.
// It is used to determine insertion order for the Ford–Johnson (merge-insertion) algorithm.
int PmergeMe::Jacobsthal(int n) {
	return (pow(2, n) - pow(-1, n)) / 3;
}

void PmergeMe::FordJohnsonSort(std::vector<int> &vec) {
	static int pair_size = 1;		// recursion depth level (*2 on each layer - 1,2,4,...)

	int nb_pairs = vec.size() / pair_size;
	if (nb_pairs < 2) {
		return;
	}

	bool is_odd = nb_pairs % 2 == 1;
	std::vector<int>::iterator start = vec.begin();
	std::vector<int>::iterator end = vec.begin() + ((pair_size * nb_pairs) - (is_odd * pair_size));
	// Define the region to operate on (exclude any trailing unmatched pair if odd)

	// For each pair, ensure the last element of the first chunk
	// is < last element of the second chunk, swapping if necessary
	for (std::vector<int>::iterator it = start; it < end ; it += (pair_size * 2)) {
		if (*(it + (pair_size - 1)) > *(it + ((pair_size * 2) - 1))) {
			for (int i = 0; i < pair_size; i++) {
				std::swap(*(it + i), *(it + pair_size + i));
			}
		}
	}

	// Recurse with doubled pair_size to process larger chunk-pairs
	pair_size *= 2;
	FordJohnsonSort(vec);
	pair_size /= 2;

	// Prepare sequences for final insertion phase
	std::vector<int> main;
	std::vector<int> pend;
	std::vector<int> non_participant;
	int odd_value = 0;

	// Initialize 'main' with the last element of the first two chunks
	main.push_back(*(start + pair_size - 1));
	main.push_back(*(start + (pair_size * 2) - 1));

	// Walk the paired region and collect pend and main elements alternately
	for (std::vector<int>::iterator it = start + pair_size * 2; it < end; it += pair_size) {
		pend.push_back(*(it + pair_size - 1));		// smaller element from the current pair
		it += pair_size;
		main.push_back(*(it + pair_size - 1));		// larger element from that pair
	}

	// If is_odd, save the leftover element to insert later
	if (is_odd) {
		odd_value = *(end + pair_size - 1);
	}

	// Non-participating elements: everything after the processed region (including possible odd chunks)
	non_participant.insert(non_participant.end(), end + (pair_size * is_odd), vec.end());

	// If we have work to do, merge pend and odd_value back into main and rebuild 'vec'
	if (is_odd || !pend.empty()) {
		FordJohnsonInsert(main, pend, odd_value, non_participant, vec, is_odd, pair_size);
	}
}

void PmergeMe::FordJohnsonInsert(std::vector<int> &main, std::vector<int> &pend, int odd_value, std::vector<int> &non_participant, std::vector<int> &vec, bool is_odd, int pair_size) {
	std::vector<int>::iterator end;

	// Simple case: single pend element -> insert using upper_bound to keep 'main' sorted
	if (pend.size() == 1) {
		end = std::upper_bound(main.begin(), main.end(), *pend.begin());
		main.insert(end, *pend.begin());
	} else if (pend.size() > 1) {
		size_t jacobsthal_index = 3;
		size_t count = 0;
		size_t pend_index;
		size_t decrease;

		while (!pend.empty()) {
			// Determine how many pend elements to take in this round using Jacobsthal
			pend_index = Jacobsthal(jacobsthal_index) - Jacobsthal(jacobsthal_index - 1);
			if (pend_index > pend.size()) {
				pend_index = pend.size();
			}

			decrease = 0;
			while (pend_index > 0) {
				end = main.begin();
				// Determine the search boundary using additional Jacobsthal numbers
				if (Jacobsthal(jacobsthal_index + count) - decrease <= main.size()) {
					end = main.begin() + Jacobsthal(jacobsthal_index + count) - decrease;
				} else {
					end = main.end();
				}

				end = std::upper_bound(main.begin(), end, *(pend.begin() + pend_index - 1));
				main.insert(end, *(pend.begin() + pend_index - 1));
				pend.erase(pend.begin() + pend_index - 1);

				pend_index--;
				decrease++;
				count++;
			}
			jacobsthal_index++;
		}
	}
	std::vector<int> return_vec;

	// If is_odd, insert it into main
	if (is_odd) {
		end = std::upper_bound(main.begin(), main.end(), odd_value);
		main.insert(end, odd_value);
	}

	// Rebuild the output vector by locating each element of 'main' in the original 'vec'
	// and copy its entire chunk (of size 'pair_size') into return_vec
	for (std::vector<int>::iterator i = main.begin(); i != main.end(); i++) {
		std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), *i);
		return_vec.insert(return_vec.end(), it - (pair_size - 1), it + 1);
	}

	return_vec.insert(return_vec.end(), non_participant.begin(), non_participant.end());
	vec = return_vec;
}

void PmergeMe::FordJohnsonSort(std::deque<int> &deq) {
	static int pair_size = 1;

	int nb_pairs = deq.size() / pair_size;
	if (nb_pairs < 2) {
		return;
	}

	bool is_odd = nb_pairs % 2 == 1;
	std::deque<int>::iterator start = deq.begin();
	std::deque<int>::iterator end = deq.begin() + ((pair_size * nb_pairs) - (is_odd * pair_size));

	for (std::deque<int>::iterator it = start; it < end ; it += (pair_size * 2)) {
		if (*(it + (pair_size - 1)) > *(it + ((pair_size * 2) - 1))) {
			for (int i = 0; i < pair_size; i++) {
				std::swap(*(it + i), *(it + pair_size + i));
			}
		}
	}

	pair_size *= 2;
	FordJohnsonSort(deq);
	pair_size /= 2;

	std::deque<int> main;
	std::deque<int> pend;
	std::deque<int> non_participant;
	int odd_value = 0;

	main.push_back(*(start + pair_size - 1));
	main.push_back(*(start + (pair_size * 2) - 1));

	for (std::deque<int>::iterator it = start + pair_size * 2; it < end; it += pair_size) {
		pend.push_back(*(it + pair_size - 1));
		it += pair_size;
		main.push_back(*(it + pair_size - 1));
	}

	if (is_odd) {
		odd_value = *(end + pair_size - 1);
	}

	non_participant.insert(non_participant.end(), end + (pair_size * is_odd), deq.end());

	if (is_odd || !pend.empty()) {
		FordJohnsonInsert(main, pend, odd_value, non_participant, deq, is_odd, pair_size);
	}
}

void PmergeMe::FordJohnsonInsert(std::deque<int> &main, std::deque<int> &pend, int odd_value, std::deque<int> &non_participant, std::deque<int> &deq, bool is_odd, int pair_size) {
	std::deque<int>::iterator end;

	if (pend.size() == 1) {
		end = std::upper_bound(main.begin(), main.end(), *pend.begin());
		main.insert(end, *pend.begin());
	} else if (pend.size() > 1) {
		size_t jacobsthal_index = 3;
		size_t count = 0;
		size_t pend_index;
		size_t decrease;

		while (!pend.empty()) {
			pend_index = Jacobsthal(jacobsthal_index) - Jacobsthal(jacobsthal_index - 1);
			if (pend_index > pend.size()) {
				pend_index = pend.size();
			}

			decrease = 0;
			while (pend_index > 0) {
				end = main.begin();
				if (Jacobsthal(jacobsthal_index + count) - decrease <= main.size()) {
					end = main.begin() + Jacobsthal(jacobsthal_index + count) - decrease;
				} else {
					end = main.end();
				}

				end = std::upper_bound(main.begin(), end, *(pend.begin() + pend_index - 1));
				main.insert(end, *(pend.begin() + pend_index - 1));
				pend.erase(pend.begin() + pend_index - 1);

				pend_index--;
				decrease++;
				count++;
			}
			jacobsthal_index++;
		}
	}
	std::deque<int> return_vec;

	if (is_odd) {
		end = std::upper_bound(main.begin(), main.end(), odd_value);
		main.insert(end, odd_value);
	}

	for (std::deque<int>::iterator i = main.begin(); i != main.end(); i++) {
		std::deque<int>::iterator it = std::find(deq.begin(), deq.end(), *i);
		return_vec.insert(return_vec.end(), it - (pair_size - 1), it + 1);
	}
	return_vec.insert(return_vec.end(), non_participant.begin(), non_participant.end());
	deq = return_vec;
}
