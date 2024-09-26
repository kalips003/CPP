#include <iostream>

#include "FixedNum.hpp"

int main( void ) {
	FixedNum a;
	FixedNum b( a );
	FixedNum c;

	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
return 0;
}