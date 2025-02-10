#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;
	data.name = "Test";

	std::cout << "Original Data: " << &data << " -> value: " << data.value << ", name: " << data.name << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized Data: " << raw << std::endl;

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data: " << deserializedData << " -> value: " << deserializedData->value << ", name: " << deserializedData->name << std::endl;

	if (&data == deserializedData)
		std::cout << "Serialization and deserialization successful!" << std::endl;
	else
		std::cout << "Serialization and deserialization failed!" << std::endl;

	return 0;
}
