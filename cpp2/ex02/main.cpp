#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << C_414 "A: \t" RESET << a << std::endl;
    std::cout << C_414 "++A: \t" RESET << ++a << std::endl;
    std::cout << C_414 "A: \t" RESET << a << std::endl;
    std::cout << C_414 "A++: \t" RESET << a++ << std::endl;
    std::cout << C_414 "A: \t" RESET << a << std::endl;
    std::cout << C_414 "--A: \t" RESET << --a << std::endl;
    std::cout << std::endl;

    std::cout << C_414 "B: \t" RESET << b << std::endl;
    std::cout << C_414 "Max(a,b): " RESET << Fixed::max( a, b ) << std::endl;
    std::cout << C_414 "Min(a,b): " RESET << Fixed::min( a, b ) << std::endl;
    std::cout << std::endl;

    std::cout << C_414 "a = 15.2f + 0.8f: " RESET << (a = 15.2f + 0.8f) << std::endl;
    std::cout << C_414 "a - 0.5f: \t" RESET << a - 0.5f << std::endl;
    std::cout << C_414 "a * 2: \t\t" RESET << a * 2 << std::endl;
    std::cout << C_414 "a / 0: \t\t" RESET << a / 0 << std::endl;
    std::cout << C_414 "a * 12.2f: \t" RESET << a * 12.2f << std::endl;
    std::cout << std::endl;

    Fixed c(3.9f);
    Fixed d(4);

    std::cout << C_323 "c = 3.9f\t d = 4" RESET << std::endl;
    std::cout << C_414 "c > d?: \t" RESET << (c > d ? "true" : "false") << std::endl;
    std::cout << C_414 "c <= d?: \t" RESET << (c <= d ? "true" : "false") << std::endl;
    std::cout << C_414 "c == c?: \t" RESET << (c == c ? "true" : "false") << std::endl;

    return 0;   
}
