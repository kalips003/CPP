#include <iostream>
#include "FixedNum.hpp"

int main( void ) {
	FixedNum a;
	FixedNum const b( FixedNum( 5.05f ) * FixedNum( 2 ) );
	std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	// std::cout << FixedNum::max( a, b ) << std::endl;
	return 0;
}
