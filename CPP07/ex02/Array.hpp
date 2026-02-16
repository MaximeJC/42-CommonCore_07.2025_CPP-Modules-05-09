#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <typename T> class Array {
private:
	T *_array;
	size_t _n;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	~Array();

	Array &operator=(const Array &src);
	T &operator[](size_t index) const;

	size_t size() const;
};

#include "Array.tpp"

#endif
