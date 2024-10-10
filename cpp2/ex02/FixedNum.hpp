#ifndef FIXEDNUM_HPP
#define FIXEDNUM_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
// std::string
// #include <vector>
// #include <map>
// #include <set>
// #include <algorithm>
// #include <cstdlib>
#include <cmath>
// #include <ctime>
// #include <iomanip>
// #include <sstream>
// #include <utility>
// #include <cassert>
// #include <cctype>
// #include "_lib.hpp"

template <typename T>
void put(const T& value) {
	std::cout << value << std::endl;
}
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS									 //]
///////////////////////////////////////////////////////////////////////////////]
class FixedNum {

/////   PRIVATE DATA
private:

	int 				int_value;
	static const int 	num_fractional_bits = 8;

public:

	FixedNum();
	template <typename N>
	FixedNum( N value ) {
		if (value > 0x7FFFFF)
			throw std::runtime_error("Value too big");
		int_value = static_cast<int>(roundf(value * (1 << num_fractional_bits)));
	}
	~FixedNum( void );
	FixedNum( const FixedNum& other );
	FixedNum& operator=( const FixedNum& other );

////
	int		toInt( void ) const;
	float	toFloat( void ) const;

	int 	getRawBits( void ) const;
	void	setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const FixedNum& n);
///////////////////////////////////////////////////////////////////////////////]
template <typename N>
bool operator>(const FixedNum& a, const N& b) {
	FixedNum temp(b);
	return a.getRawBits() > temp.getRawBits();
}
template <typename N>
bool operator<(const FixedNum& a, const N& b) {
	FixedNum temp(b);
	return a.getRawBits() < temp.getRawBits();
}
template <typename N>
bool operator>=(const FixedNum& a, const N& b) {
	FixedNum temp(b);
	return a.getRawBits() >= temp.getRawBits();
}
template <typename N>
bool operator<=(const FixedNum& a, const N& b) {
	FixedNum temp(b);
	return a.getRawBits() <= temp.getRawBits();
}
template <typename N>
bool operator!=(const FixedNum& a, const N& b) {
	FixedNum temp(b);
	return a.getRawBits() != temp.getRawBits();
}
template <typename N>
bool operator==(const FixedNum& a, const N& b) {
	FixedNum temp(b);
	return a.getRawBits() == temp.getRawBits();
}

///////////////////////////////////////////////////////////////////////////////]
template <typename N>
FixedNum operator+(const FixedNum& a, const N& b) {
	FixedNum rtrn(b);
	rtrn.setRawBits(a.getRawBits() + rtrn.getRawBits());
	return rtrn;
}
template <typename N>
FixedNum operator-(const FixedNum& a, const N& b) {
	FixedNum rtrn(b);
	rtrn.setRawBits(a.getRawBits() - rtrn.getRawBits());
	return rtrn;
}
template <typename N>
FixedNum operator*(const FixedNum& a, const N& b) {
	FixedNum rtrn(b);
	long temp = (a.getRawBits() * rtrn.getRawBits()) >> 8;
	rtrn.setRawBits(static_cast<int>(temp));
	return rtrn;
}
template <typename N>
FixedNum operator/(const FixedNum& a, const N& b) {
	FixedNum rtrn(b);
	if (b == 0)
		throw std::runtime_error("Division by zero");
	rtrn.setRawBits(a.getRawBits() / rtrn.getRawBits());
	return rtrn;
}



#endif

