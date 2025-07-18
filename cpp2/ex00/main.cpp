#include <iostream>
#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << std::endl;

	int bit;
	bit = a.getRawBits();
	std::cout << C_423 "Raw bits A: \t" RESET << bit << std::endl;
	a.setRawBits(6546);
	bit = a.getRawBits();
	std::cout << C_423 "Raw bits A: \t" RESET << bit << std::endl;

	bit = b.getRawBits();
	std::cout << C_423 "Raw bits B: \t" RESET << bit << std::endl;

	bit = c.getRawBits();
	std::cout << C_423 "Raw bits C: \t" RESET << bit << std::endl;
	
	std::cout << std::endl;

	return 0;
}

// > ./a.out
// Default constructor called
// Copy constructor called
// Copy assignment operator called // <-- This line may be missing depending on your implementation
// getRawBits member function called
// Default constructor called
// Copy assignment operator called
// getRawBits member function called
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// Destructor called
// Destructor called
// Destructor called
// $>