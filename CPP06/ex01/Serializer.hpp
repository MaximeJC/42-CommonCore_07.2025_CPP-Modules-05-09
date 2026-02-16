#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <cstring>
#include <stdint.h>
#include "main.hpp"


class Serializer {
private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
