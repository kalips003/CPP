#include "FixedNum.hpp"

///////////////////////////////////////////////////////////////////////////////]
//  FixedNum Orthodox Canonical Form
FixedNum::FixedNum() : int_value(0) {
	put("Default constructor called");
}

FixedNum::FixedNum(const int a) : int_value(a << num_fractional_bits) {
	put("Int constructor called");
}

FixedNum::FixedNum(const float a) {
	int_value = roundf(a * (1 << num_fractional_bits));
	put("Float constructor called");
}

FixedNum::~FixedNum() {
	put("Destructor called");
}
FixedNum::FixedNum(const FixedNum& other) {
	int_value = other.int_value;
	put("Copy constructor called");
}
FixedNum& FixedNum::operator=(const FixedNum& other) {
	if (this != &other) {
		put("Copy assignment operator  called");
		// delete data;  // Clean up old resource
		// data = new int(*other.data);  // Deep copy
		int_value = other.int_value;
	}
	return *this;
}

//  SETTER & GETTER
int FixedNum::getRawBits( void ) const {
	put("getRawBits member function called");
	return int_value;
}
void FixedNum::setRawBits( int const raw ) {
	int_value  = raw;
	put("setRawBits member function called");
}

float FixedNum::toFloat( void ) const {

	return 0.0;
}

int FixedNum::toInt( void ) const {

	return int_value >> num_fractional_bits;
}