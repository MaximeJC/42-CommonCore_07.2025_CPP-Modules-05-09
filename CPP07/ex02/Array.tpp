#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T[0]()), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _n(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(new T[src._n]()), _n(src._n) {
	for (size_t i = 0; i < _n; i++) {
		_array[i] = src._array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src) {
	if (this != &src) {
		delete[] _array;
		_n = src._n;
		_array = new T[_n]();
		for (size_t i = 0; i < _n; i++) {
			_array[i] = src._array[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](size_t index) const {
	if (index >= _n) {
		throw std::out_of_range("Index out of range");
	}
	return _array[index];
}

template <typename T>
size_t Array<T>::size() const {
	return _n;
}

#endif
