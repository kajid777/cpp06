#include "Serializer.hpp"
#include <iostream>

int main() {
	Data data;
	data.value = 42;
	data.name = "test";

	Data* originalPtr = &data;
	std::cout << "Original pointer: " << originalPtr << std::endl;

	uintptr_t raw = Serializer::serialize(originalPtr);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* deserializedPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

	if (originalPtr == deserializedPtr) {
		std::cout << "Pointers are equal!" << std::endl;
		std::cout << "Data value: " << deserializedPtr->value << std::endl;
		std::cout << "Data name: " << deserializedPtr->name << std::endl;
	} else {
		std::cout << "Pointers are NOT equal!" << std::endl;
		return 1;
	}

	return 0;
}

