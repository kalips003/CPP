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

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class FixedNum {
public:
/////   Orthodox Canonical Form
	FixedNum( void );  // Default constructor
	FixedNum( int );  // Default constructor
	FixedNum( float );  // Default constructor
	~FixedNum( void );  // Destructor
	FixedNum( const FixedNum& other );  // Copy constructor
	FixedNum& operator=( const FixedNum& other );  // Copy assignment operator


/////   PRIVATE DATA
private:
	int int_value;
	static const int num_fractional_bits = 8;


/////   PUBLIC DATA
public:
	float toFloat( void ) const;
	int toInt( void ) const;
	// std::string label;

/////   FONCTIONS D'USAGE
public:
	// FixedNum& operator+( const FixedNum& other ) {};
	// FixedNum( int i, const std::string& s ) : attribute(i), label(s) {}

/////   PUBLIC SETTER GETTER
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

template <typename T>
void put(T& value) {
	std::cout << value << std::endl;
}


#endif

