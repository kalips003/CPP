#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
#include <stdint.h>

#include "../_colors.h"

struct Data {
	int a;
	int b;

	Data() : a(0), b(0) {}
	Data(int a, int b) : a(a), b(b) {}
};

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class Serializer {

private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer& operator=(const Serializer& other);

protected:

public:

/////   CANONICAL
	~Serializer();

/////
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

};

#endif
