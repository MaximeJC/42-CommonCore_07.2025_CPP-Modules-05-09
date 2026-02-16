#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>
#include <climits>

class Span {
private:
	unsigned int _n;
	std::vector<int> _vec;
	Span();
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void addNumber(int number);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();

	class SpanFullException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class NotEnoughNumbersException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
