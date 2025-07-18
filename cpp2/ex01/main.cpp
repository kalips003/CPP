#include <iostream>
#include "Fixed.hpp"


int main( void ) {

    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    Fixed const e( 10000000 );
    a = Fixed( 1234.4321f );

    std::cout << std::endl;
    std::cout << "a is " << C_225 << a << RESET << std::endl;
    std::cout << "b is " << C_225 << b << RESET << std::endl;
    std::cout << "c is " << C_225 << c << RESET << std::endl;
    std::cout << "d is " << C_225 << d << RESET << std::endl;
    std::cout << "e is " << C_225 << e << RESET << std::endl;
    std::cout << std::endl;
    std::cout << "a is " << C_225 << a.toInt() << RESET << " as an integer" << std::endl;
    std::cout << "b is " << C_225 << b.toInt() << RESET << " as an integer" << std::endl;
    std::cout << "c is " << C_225 << c.toInt() << RESET << " as an integer" << std::endl;
    std::cout << "d is " << C_225 << d.toInt() << RESET << " as an integer" << std::endl;
    std::cout << "e is " << C_225 << e.toInt() << RESET << " as an integer" << std::endl;
    std::cout << std::endl;
    std::cout << "a is " << C_225 << a.toFloat() << RESET << " as a float" << std::endl;
    std::cout << "b is " << C_225 << b.toFloat() << RESET << " as a float" << std::endl;
    std::cout << "c is " << C_225 << c.toFloat() << RESET << " as a float" << std::endl;
    std::cout << "d is " << C_225 << d.toFloat() << RESET << " as a float" << std::endl;
    std::cout << "e is " << C_225 << e.toFloat() << RESET << " as a float" << std::endl;
    std::cout << std::endl;

    return 0;
}
