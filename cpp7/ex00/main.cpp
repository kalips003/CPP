#include "src/Whatever.hpp"

#include <iostream>

///////////////////////////////////////////////////////////////////////////////]
int main() {

    int a = 5;
    int b = 6;
    float f1 = 3.9f;
    float f2 = 3.8f;

    int result = min(a, b);
    float result2 = max(f1, f2);
    std::cout << C_141 "MIN: " RESET << result << std::endl;
    std::cout << C_132 "MAX: " RESET << result2 << std::endl;

    std::cout << C_145 "Before swap: (" RESET << a << C_145 ", " RESET << b << C_145 ")" RESET << std::endl;
    swap(a, b);
    std::cout << C_145 "After swap: (" RESET << a << C_145 ", " RESET << b << C_145 ")" RESET << std::endl;
	return 0;
}

// int main( void ) {
    // int a = 2;
    // int b = 3;
    // ::swap( a, b );
    // std::cout << "a = " << a << ", b = " << b << std::endl;
    // std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    // std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    // std::string c = "chaine1";
    // std::string d = "chaine2";
    // ::swap(c, d);
    // std::cout << "c = " << c << ", d = " << d << std::endl;
    // std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    // std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    // return 0;
// }