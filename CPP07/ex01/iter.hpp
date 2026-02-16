#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, size_t const size, void (*f)(T &)) {
	for (size_t i = 0; i < size; i++) {
		f(array[i]);
	}
}

#endif
