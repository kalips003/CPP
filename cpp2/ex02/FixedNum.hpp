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

template FixedNum::FixedNum(float);
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS									 //]
///////////////////////////////////////////////////////////////////////////////]
class FixedNum {

/////   PRIVATE DATA
private:

	int 				int_value;
	static const int 	num_fractional_bits = 8;

public:
/////   Orthodox Canonical Form

FixedNum();

template <typename N>
FixedNum( N value ) {
	if (value > 0x7FFFFF)
		throw std::runtime_error("Value too big");
	int_value = static_cast<int>roundf(value * (1 << num_fractional_bits));
}

	FixedNum( float );  // Default constructor
	~FixedNum( void );  // Destructor
	FixedNum( const FixedNum& other );  // Copy constructor
	FixedNum& operator=( const FixedNum& other );  // Copy assignment operator

	float	toFloat( void ) const;
	int		toInt( void ) const;

	int 		getRawBits( void ) const;
	void		setRawBits( int const raw );


};

template <typename N>
bool operator>(const FixedNum& a, const N& b) {
	FixedNum temp(b);
	return a.getRawBits() > temp.getRawBits();
}

bool operator>(const FixedNum& a, const FixedNum& b);
bool operator<(const FixedNum& a, const FixedNum& b);
bool operator>=(const FixedNum& a, const FixedNum& b);
bool operator<=(const FixedNum& a, const FixedNum& b);
bool operator!=(const FixedNum& a, const FixedNum& b);
bool operator==(const FixedNum& a, const FixedNum& b);

FixedNum operator+(const FixedNum& a, const FixedNum& b);
FixedNum operator-(const FixedNum& a, const FixedNum& b);
FixedNum operator*(const FixedNum& a, const FixedNum& b);
FixedNum operator/(const FixedNum& a, const FixedNum& b);

std::ostream& operator<<(std::ostream& os, const FixedNum& n);

template <typename T>
void put(const T& value) {
	std::cout << value << std::endl;
}



#endif

