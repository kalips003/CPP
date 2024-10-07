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
	return static_cast<float>(int_value) / (1 << num_fractional_bits);
}

int FixedNum::toInt( void ) const {
	return int_value >> num_fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const FixedNum& n) {
	os << n.toFloat();
	return os;
}

//  OPERATORS
bool operator>(const FixedNum& a, const FixedNum& b) {
	return a.getRawBits() > b.getRawBits() ? 1 : 0;
}
bool operator<(const FixedNum& a, const FixedNum& b) {
	return a.getRawBits() < b.getRawBits() ? 1 : 0;
}
bool operator>=(const FixedNum& a, const FixedNum& b) {
	return a.getRawBits() >= b.getRawBits() ? 1 : 0;
}
bool operator<=(const FixedNum& a, const FixedNum& b) {
	return a.getRawBits() <= b.getRawBits() ? 1 : 0;
}
bool operator!=(const FixedNum& a, const FixedNum& b) {
	return a.getRawBits() != b.getRawBits() ? 1 : 0;
}
bool operator==(const FixedNum& a, const FixedNum& b) {
	return a.getRawBits() == b.getRawBits() ? 1 : 0;
}


FixedNum operator+(const FixedNum& a, const FixedNum& b) {
	FixedNum rtrn;
	rtrn.setRawBits(a.getRawBits() + b.getRawBits());
	return rtrn;
}
FixedNum operator-(const FixedNum& a, const FixedNum& b) {
	FixedNum rtrn;
	rtrn.setRawBits(a.getRawBits() - b.getRawBits());
	return rtrn;
}
FixedNum operator*(const FixedNum& a, const FixedNum& b) {
	FixedNum rtrn;
	rtrn.setRawBits(a.getRawBits() * b.getRawBits());
	return rtrn;
}
FixedNum operator/(const FixedNum& a, const FixedNum& b) {
	if (b == 0)
		throw std::runtime_error("Division by zero");
	FixedNum rtrn;
	rtrn.setRawBits(a.getRawBits() / b.getRawBits());
	return rtrn;
}
