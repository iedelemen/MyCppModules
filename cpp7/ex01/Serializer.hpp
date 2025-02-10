#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>
using std::string;

struct Data
{
	int value;
	string name;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &obj);
		~Serializer();
		Serializer &operator=(const Serializer &obj);
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
