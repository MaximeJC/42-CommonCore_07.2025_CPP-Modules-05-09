#include "Span.hpp"

Span::Span() : _n(0), _vec() {}

Span::Span(unsigned int n) : _n(n), _vec() {}

Span::Span(const Span &other) : _n(other._n), _vec(other._vec) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_n = other._n;
		_vec = other._vec;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_vec.size() >= _n)
		throw SpanFullException();
	_vec.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + _vec.size() > _n)
		throw SpanFullException();
	_vec.insert(_vec.end(), begin, end);
}

int Span::shortestSpan() {
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> sortedVec = _vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	int minSpan = INT_MAX;
	for (size_t i = 1; i < sortedVec.size(); ++i) {
		int span = sortedVec[i] - sortedVec[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
	int minElem = *std::min_element(_vec.begin(), _vec.end());
	int maxElem = *std::max_element(_vec.begin(), _vec.end());
	return maxElem - minElem;
}

const char* Span::SpanFullException::what() const throw() {
	return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw() {
	return "Not enough numbers to find a span";
}
