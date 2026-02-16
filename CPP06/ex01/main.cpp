#include "Serializer.hpp"

int main() {
	Data data;
	data.n = 42;
	data.s1 = "Hello";
	data.f = 3.14f;
	data.s2 = "World";
	std::cout << "Original Data:" << std::endl;
	std::cout << "n: " << data.n << std::endl;
	std::cout << "s1: " << data.s1 << std::endl;
	std::cout << "f: " << data.f << std::endl;
	std::cout << "s2: " << data.s2 << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "n: " << deserializedData->n << std::endl;
	std::cout << "s1: " << deserializedData->s1 << std::endl;
	std::cout << "f: " << deserializedData->f << std::endl;
	std::cout << "s2: " << deserializedData->s2 << std::endl;
	return 0;
}
